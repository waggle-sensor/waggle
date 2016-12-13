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