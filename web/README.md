# Documentation for web publishing

Web pages that describe about Waggle are necessary in order to provide information of the latest stable version of Waggle to users. Github markdown files placed in our github repositories are used to generate such web pages. This means that contents of the web pages come from the corresponding markdown files. This allows developers to maintain their web site by just editing the markdown files and compiling them to make updated web pages.

<img src="res/web-doc-diagram.png" width=400 /> <br>

## Generate html files

In order to make web pages, a file list should be updated and checked. The file list is located under __'res'__ folder and contains pairs of links between the paths of a markdown file and the corresponding web page. For example, __'index.md:index.html'__ (':' is delimiter) describes that __'index.md'__ is the source of __'index.html'__. If one of the links or pairs changed in git repositories, it must be updated in the file list before compilation.

To generate html files use:

```bash
make docs
```

To clean all generated html files under this web folder use:

```bash
make clean
```

In order to publish the generated html files along with the images, set up a variable called __'INSTALL_URL'__. The variable must contain remote address of the destination and location where all the files will be transferred. An example of the correct URL would be:

```bash
export INSTALL_URL=remote_user_name@remote_address:where/html/files/go # in linux
```

After the variable is set use:

```bash
make install
```
This process requires you to put the password for 'remote_user_name'. Now the web directory (waggle_web as default) is in the remote address under the path set in INSTALL_URL variable.

## Linking python scripts to html files

If an html file needs technical support such as code snippets, the corresponding md file includes a special tag which specifies the code snippet generated from Sphinx. Below is an example of the tag.

```
<!-- EXTERNAL LINK TO CODE
"html/guestNode/GN_registration.html"
-->
```

GN_registration.html includes code snippet and supporting explanation. The file must exist before __'make docs'__. The path assumes that it starts from __'waggle/docs/_build'__ such that the GN_Registration.html file exists under waggle/docs/_build/html/guestNode.

## Deverloper notes

* pandoc uses style.css under __'res'__ folder, which has MIT license.
* All images that have relative links and used in the markdown files will be copied into __'ROOT_WEB_DIR/Img'__.
* Relative links for other web pages (shown only in the file list) or images are re-routed using the path of html files while absolute links remain untouched.
* Further information about compilation can be found at [Pandoc](http://pandoc.org)
