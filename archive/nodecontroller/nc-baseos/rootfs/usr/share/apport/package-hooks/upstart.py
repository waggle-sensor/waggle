#!/usr/bin/python
'''
Upstart apport hook.

Handles both Upstart running as PID 1 and as a Session Init
(non-privileged user).

Limitations:

- does not handle non-default --logdir or --confdir.

'''
import os
import re
import glob
from apport.hookutils import *
import apport.packaging

msg = \
"""
The contents of your Upstart job configuration files (*.conf and
*.override) files may help developers diagnose your bug more quickly.
However, if you have modified them, they may contain sensitive
information.

Do you want to include any modified job configuration files
in your bug report?
"""

def add_root_file(map, file):
    """
    Add @file to @map such that @map can be passed to
    attach_root_command_outputs() to have @file attached to the report
    event if it is unreadable by the current user.
    """
    if not os.path.exists(file):
        return

    key = path_to_key(file)

    map[key] = 'cat %s' % file


def add_info(report, ui):
    system_state_file = '/var/log/upstart/upstart.state'
    system_conf_dir = '/etc/init'
    session_state_file = None
    attach_jobs = False
    package = None

    # files that are not readable by current user
    unreadable_files = {}

    # Used to determine which details to record.
    #
    # For crashes, hangs and recoverable problems, attach all possible
    # information.
    #
    # If we are unable to determine a problem category, prompt the user.
    category = 'Unknown'

    if 'Package' in report:
        package = report['Package'].split()[0]

    problem_type = report.get('ProblemType', '')

    # Determine whether this report relates to a System Init issue,
    # or a Session Init one.

    # Crashes and Hangs should be handled automatically without
    # prompting. Recoverable Problems should also be dealt with in this
    # way since they are essentially informational reports so prompting
    # the user is unnecessary and would also only give the user the wrong
    # impression.
    if problem_type in ('Crash', 'Hang', 'RecoverableProblem'):
        if 'ProcStatus' in report:
            pid_line = re.search('Pid:\t(.*)\n', report['ProcStatus'])
            if pid_line:
                upstart_pid = pid_line.groups()[0]
                if upstart_pid:
                    if int(upstart_pid) == 1:
                        category = 'System'
                    else:
                        category = 'Session'
    elif ui:
        response = ui.choice(
            "Upstart is used to supervise both the System and users Desktop\n"
            "sessions. Please choose the option that is most appropriate\n"
            "for the problem you wish to report\n",
            ['System', 'Desktop Session'])
        if response == None:
            pass
        if 0 in response:
            category = 'System'
        elif 1 in response:
            category = 'Session'

    report['UpstartBugCategory'] = category

    if problem_type in ('Crash', 'Hang', 'RecoverableProblem'):
        # crash bugs are private by default
        attach_jobs = True
    elif ui and ui.yesno(msg) == True:
        attach_jobs = True

    if category == 'System' or category == 'Unknown':
        attach_file(report, '/proc/cmdline', 'ProcKernelCmdline')

        # console output
        attach_file_if_exists(report, '/var/log/boot.log', 'BootLog')

        if attach_jobs == True:

            # Map of files => package names where each file is an Upstart
            # job configuration file.
            file_map = {}

            for file in \
                glob.glob("%s/*.conf"     % system_conf_dir) + \
                glob.glob("%s/*.override" % system_conf_dir):

                # try and determine which package owns the file
                owner = apport.packaging.get_file_package(file)

                if owner == None:
                    # If no package owns it, it's either an admin-created
                    # job, or from a manually installed package, so attach.
                    # XXX: We don't use attach_file() since, although it
                    # handles unreadable files in a sense (by returning
                    # an error string), it does not allow us to grab the
                    # file contents.
                    add_root_file(unreadable_files, file)
                elif owner != package and owner not in set(file_map.values()):
                    # If the file is owned by another package,
                    # record the package name.
                    #
                    # XXX: note that we exclude the file if it is owned by
                    # the Upstart package itself since the general hooks
                    # already look for modified conffiles.
                    file_map[file] = owner

            # Attach all modified conffiles for all packages which
            # provide Upstart jobs.
            for pkg in set(file_map.values()):
                attach_conffiles(report, pkg)

    if category == 'Session' or category == 'Unknown':
        log_dir = os.getenv('XDG_CACHE_HOME', os.path.expanduser('~/.cache/upstart/'))
        conf_dir = os.getenv('XDG_CONFIG_HOME', os.path.expanduser('~/.config/upstart/'))
        old_conf_dir = os.path.expanduser('~/.init/')
        session_state_file = os.path.join(log_dir, 'upstart.state')

        if attach_jobs == True:
            for file in \
                glob.glob("%s/*.conf"     % conf_dir) + \
                glob.glob("%s/*.override" % conf_dir) + \
                glob.glob("%s/*.conf"     % old_conf_dir) + \
                glob.glob("%s/*.override" % old_conf_dir):
                attach_file(report, file)

    add_root_file(unreadable_files, system_state_file)

    attach_root_command_outputs(report, unreadable_files)

    if session_state_file:
        attach_file_if_exists(report, session_state_file)

    if os.path.exists(system_state_file) or (session_state_file and os.path.exists(session_state_file)):
        report['Tags'] += ' ' + 'upstart-stateful-reexec-failed'

    report['UpstartRunningSystemVersion'] = command_output(['initctl', '--system', 'version'])

    if category == 'System' or category == 'Unknown':
        report['UpstartRunningSystemJobs'] = command_output(['initctl', '--system', 'list'])

    session_count = 0
    if category == 'Session' or category == 'Unknown':
        sessions = command_output(['initctl', 'list-sessions']).split('\n')
        if sessions and sessions[0]:
            session_count = len(sessions)
            report['UpstartRunningSessionCount'] = str(session_count)

    # join the running session if possible
    if not os.environ.get('UPSTART_SESSION', None) and session_count == 1:
        session = sessions[0].strip().split()[1]
        if session:
            os.environ['UPSTART_SESSION'] = session

    if os.environ.get('UPSTART_SESSION', None):
        report['UpstartRunningSessionVersion'] = command_output(['initctl', 'version'])
        report['UpstartRunningSessionJobs'] = command_output(['initctl', 'list'])
