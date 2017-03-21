
![waggle banner](http://www.mcs.anl.gov/research/projects/waggle/docs/Img/banner.png)

This directory holds tools and instructions for managing the BSD-style
open source license for Waggle.

## Instructions and Procedures:

1. **Every repo should have a LICENSE file** The root directory for
every waggle-based software repository or distribution should have the
file "LICENSE.waggle.txt".  That file should be copied directly from
this directory, and if changes are made to the version here, the file
should be pushed out to all the repos.  The file describes, in full,
the legal copyright and licensing for Waggle software.

2. **Every repo should have a README file** The root directory for
every waggle-based software repository or distribution should have the
file "README.waggle.txt".  That file should be copied directly from
this directory, and if changes are made to the version here, the file
should be pushed out to all the repos. The file briefly describes the
project, and points people to the website for more information.

3. **Source code originally authored by a Waggle contributor must
include a license reference** To keep the license and copyright
intrusions in the source code as small as possible, a small *insert*
must be automatically added to the top of each file via the script
*aclsrcfix* (see below). Authors of new program files should run the
script to insert the license notification. Running the script against
a source file also signifies that the source code was authored by a
Waggle team member, and not derived from someone else's copyrighted
material.

4. **Source code authored elsewhere, and modified by a Waggle
contributor should be marked** Often, it is necessary to modify
existing source code that was originally authored outside the Waggle
project.  Such code could have an Apache, GPL, LGPL, or BSD license.
Significant additions or modifications to such code should include a
one-line notification.  Use one of the following styles:

 # This source code was modified by the Waggle Project. The original
 # license remains. Copyright UChicago and Argonne Natl Laboratory.

 or

 // This source code was modified by the Waggle Project. The original
 // license remains. Copyright UChicago and Argonne Natl Laboratory.

Please follow this with a short comment block describing the changes
to the original code done for the Waggle project.

## Using the source code modification script:

The script *aclsrcfix* can insert or automatically update
[aclsrcfix](https://github.com/waggle-sensor/waggle/blob/master/utils/open_source_license/aclsrcfix)
is the script.
