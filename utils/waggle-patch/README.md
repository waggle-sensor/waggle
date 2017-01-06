# Make a patch file for waggle software

To maintain versions of Waggle software __make_patch__ script generates patch files for target version of a specific Waggle software (e.g., __core__, __nodecontroller__, etc). The script assumes that the system that runs it has the latest Waggle software using ```git pull```. To use...

```bash
$make_patch -h
usage: make_patch [-h] -r REPO_PATH -b BASE -t TARGET [-o O]
                  [--pre-script PRE_SCRIPT] [--post-script POST_SCRIPT]

Generate a patch file for Waggle

optional arguments:
  -h, --help            show this help message and exit
  -r REPO_PATH, --repo-path REPO_PATH
                        The path of the Waggle repository
  -b BASE, --base BASE  Specify a git tag for baseline
  -t TARGET, --target TARGET
                        Specify a git tag for target version
  -o O                  Specify output directory
  --pre-script PRE_SCRIPT
                        Specify a script that runs before update
  --post-script POST_SCRIPT
                        Specify a script that runs after update
```

For example
```bash
$ make_patch -r /path/to/repo/core -b v1.0.0 -t v2.0.0 -o /path/to/patch/archive --pre-script /path/to/the/script --post-script /path/to/the/script

$ ls /path/to/patch/archive
-rw-rw-r-- 1 user user 349 Dec 13 14:56 core-v2.0.0.tar.gz
```

Generated patch files will be used by __waggle-update__ service running on Waggle nodes.

# Update for Internet-disabled devices
* For Internet-disabled devices (XU4s) they can be patched if they get commits from git. To make commits do
```bash
# make patch files on update server
$ cd /path/to/repo
$ git checkout TARGET_VERSION
$ git format-patch BASE_VERSION -o ../patch
$ ls -l ../patch
-rw-rw-r-- 1 theone theone  938 Dec 14 10:22 0001-Allow-waggle-init-to-finish-when-booted-off-the-eMMC.patch
-rw-rw-r-- 1 theone theone  737 Dec 14 10:22 0002-change-default-heartbeat-mode.patch
-rw-rw-r-- 1 theone theone  780 Dec 14 10:22 0003-enable-persistent-systemd-journaling.patch
-rw-rw-r-- 1 theone theone  645 Dec 14 10:22 0004-allow-root-logins.patch
-rw-rw-r-- 1 theone theone 1776 Dec 14 10:22 0005-Wagman-firmware-update-scripts.patch
-rw-rw-r-- 1 theone theone  896 Dec 14 10:22 0006-Progress-on-Wagman-update-script.patch
-rw-rw-r-- 1 theone theone 4878 Dec 14 10:22 0007-add-waggle-update-service-in-progress.patch
-rw-rw-r-- 1 theone theone 3800 Dec 14 10:22 0008-add-systemd-script-improve-waggle-update.patch
-rw-rw-r-- 1 theone theone 2745 Dec 14 10:22 0009-fix-bug.patch
-rw-rw-r-- 1 theone theone 2609 Dec 14 10:22 0010-update-waggle-update-script.patch

# update the patch files on devices that need update
# ASSUMPTION: the device already got the patch files somehow (e.g., file transfer via C1+)
$ cd /path/to/repo
# clean up the repo
# WARNING: any changes already made in the repo will be deleted!
$ git reset --hard
$ git clean -f
$ git am < /path/to/patch/folder
```
* There are two issues that can occur during update.
  + One issue is that ```git am``` may fail to apply commits when the changes of the commit cannot happen in the repository. We may skip the commit but should thoroughly examine that we can skip the commit to reach to target version.
  + The other issue is that ```git am``` put newly generated commit-ids on each commit. This results in having the same content for both the repository in the device and the repository in git server, but having different commit logs between them. 
