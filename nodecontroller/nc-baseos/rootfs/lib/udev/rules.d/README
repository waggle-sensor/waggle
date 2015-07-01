The files in this directory are read by udev(7) and used when events
are performed by the kernel.  The udev daemon watches this directory
with inotify so that changes to these files are automatically picked
up, for this reason they must be files and not symlinks to another
location as in the case in Debian.

These are not conffiles.  If you want to override the behaviour, you
can do one of two things:

 1) Write your own rules in /etc/udev/rules.d that assign the name,
    symlinks, permissions, etc. that you want.  Pick a number higher
    than the rules you want to override, and yours will be used.

 2) Copy the file to /etc/udev/rules.d and edit it there; you
    should generally only do this if you want to prevent a program
    from being run.


Files should be named xx-descriptive-name.rules, the xx should be
chosen first according to the following sequence points:

 < 60  rules shipped in packages; these can be overriden by later or
       default rules unless := is used in assignment.

       these cannot access persistent information such as that from
       blkid

 < 70  rules that run helpers such as blkid to populate the udev db

 < 90  rules that run other programs (often using information in the
       udev db)

 >=90  rules that should run last

Common locations for package rules:

 40-xx general rules, setting names and permissions
 65-xx rules to populate the udev db
 85-xx rules to run programs

