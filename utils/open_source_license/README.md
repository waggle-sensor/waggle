<!--
waggle_topic=/waggle/organization
-->

![waggle banner](http://www.mcs.anl.gov/research/projects/waggle/docs/Img/banner.png)

# Managing Open Source Licenses

The Waggle project uses BSD-style open source licenses.  This directory holds the tools and instructions for marking and managing source code files.

## Instructions and Procedures:

1. **Every repo should have a LICENSE file:** The root directory for
every waggle-based software repository or distribution should have the
file [LICENSE.waggle.txt](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/LICENSE.waggle.txt)

 That file should be copied directly from
this directory, and if changes are made to the version here, the file
should be pushed out to all the repos.  The file describes, in full,
the legal copyright and licensing for Waggle software.

2. **Every repo should have a README file:** The root directory for
every waggle-based software repository or distribution should have the
file [README.waggle.txt](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/README.waggle.txt)

 That file should be copied directly from
this directory, and if changes are made to the version here, the file
should be pushed out to all the repos. The file briefly describes the
project, and points people to the website for more information.

3. **Source code originally authored by a Waggle contributor must
include a license reference:** To keep the license and copyright
intrusions in the source code as small as possible, a small *insert*
must be automatically added to the top of each file via the script
[*aclsrcfix*](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/aclsrcfix) (see below). 
Inserts are labled, so the script can automatically find and replace them when they must be updated. Original waggle code will use the label "**waggle-license**". Authors of new program files should run the
script to insert the license notification. Running the script against
a source file also signifies that the source code was authored by a
Waggle team member, and not derived from someone else's copyrighted
material.

4. **Source code authored elsewhere, and modified by a Waggle
contributor should be marked:** Often, it is necessary to modify
existing source code that was originally authored outside the Waggle
project.  Such code could have an Apache, GPL, LGPL, or BSD license.
Significant additions or modifications to such code should include a
very short notification in the source code.  Such short notifications should also be automatically added via the script [*aclsrcfix*](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/aclsrcfix) (see below). The lable "**contrib-license**" should be used.  Waggle team programmers that make significant contributions to a source code file should insert the contrib-license text to clearly identify that the original license remains in place.  
 
Please follow the comment block inserted by [*aclsrcfix*](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/aclsrcfix) with a short description of the changes to the original code done for the Waggle project.

5. **Marking documentation:**  Instructions for marking documentation or programming guides written in LaTeX or HTML will be provided shortly.  This remains a ToDo item.

 
## Using *aclsrcfix* to Modify Source Code:

Yes, automatically modifying source code is tricky, but since license agreements and copyrights change, it is best if the license *insert* in the source code is managed by a script that can insert, replace, or remove the block.

The script *aclsrcfix* can insert or automatically update
[aclsrcfix](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/aclsrcfix)
source code based on simple marker tags in the file. Several standard comment types can be handled.  The script to do this is very old perl and could be re-written in python, but does the job. We certainly applaud anyone who wants to re-write this in during their hobby time.  

###Basic Operation###

The most common usage of the program is to add in or refresh a license insert.  Here is a super simple example for marking a source code file that was originally authored by a Waggle team member:

```
$ head -3 utility.py
import sys, time, os

def links(link, start_tag, end_tag):

$ ./aclsrcfix --label=waggle-license --insert=LICENSE.waggle.insert.txt utility.py
utility.py:
no exisiting comment block, one was added

$head -8 utility.py
#!/usr/bin/python
# ANL:waggle-license
#  This file is part of the Waggle Sensor Project.  Please see the file
#  LICENSE.waggle.txt for the legal details of the copyright and software
#  license.  For more details on the Waggle project, visit:
#           http://www.wa8.gl
# ANL:waggle-license
import sys, time, os

```

The script added a comment block, using the special prefix "ANL:" and the label **"waggle-license"**, which should be used for managing the waggle open source license.  The file [LICENSE.waggle.insert.txt](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/LICENSE.waggle.insert.txt) holds the text that is inserted into the file utility.py

Running the command again will not add another license block, but replace the text insert with the most current version.

```
$ ./aclsrcfix --label=waggle-license --insert=LICENSE.waggle.insert.txt utility.py
utility.py: comment block 'waggle-license' replaced
```

Similarly, to add the neede comment block for source code files that already had licenses from another project, such as Apache or GPL, only the **"contrib-license"** insert is needed.  Here is an example:

```
$ ./aclsrcfix --label=contrib-license --insert=LICENSE.contrib.insert.txt install-stress-ng.sh
install-stress-ng.sh: no exisiting comment block, one was added

$ head -10 install-stress-ng.sh
#!/bin/bash
# ANL:contrib-license
#  This file was modified by the Waggle Project. The original license
#  remains. Copyright UChicago and Argonne Natl Laboratory.
# ANL:contrib-license

set -e
set -x

VERSION="0.07.18"
```

For more information on on the script, just run

```
$ ./aclsrcfix --usage
```

Or, look straight at the old perl code if you enjoy archeology.


