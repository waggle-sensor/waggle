#!/usr/bin/python3
'''
Mountall apport hook.
'''

import os
from apport.hookutils import *
import apport.packaging
import glob

msg = \
"""
The contents of your /etc/fstab file and relevant log files may help
developers diagnose your bug more quickly. However, if you have modified
/etc/fstab, these files may contain sensitive information.

Do you want to include the files in your bug report? (you will be able
to review the data before it is sent)
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
    attach_files = False

    # files that are not readable by current user
    unreadable_files = {}

    problem_type = report.get('ProblemType', '')

    if problem_type == 'Bug' and ui:
        if ui.yesno(msg) == None:
            raise StopIteration
        attach_files = True
    elif problem_type == 'Crash':
        # crash bugs are private by default
        attach_files = True

    if attach_files == False:
        return

    attach_file(report, '/etc/fstab')
    attach_file(report, '/etc/mtab')
    attach_file(report, '/proc/cmdline', 'ProcKernelCmdline')
    attach_file(report, '/proc/mounts', 'ProcMounts')
    attach_file(report, '/proc/self/mountinfo', 'ProcSelfMountinfo')
    attach_file_if_exists(report, '/run/mount/utab')

    report['Mounts'] = apport.hookutils.command_output(['mount'])

    # mountall logs to the console so until Upstart can log to both the
    # console and a file, grab the plymouth log which captures the
    # console.
    add_root_file(unreadable_files, '/var/log/boot.log')

    # in case admin changed the console stanza
    add_root_file(unreadable_files, '/var/log/upstart/mountall.log')

    attach_root_command_outputs(report, unreadable_files)
