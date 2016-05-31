# Documentation for web publishing

Web pages that describe about Waggle are necessary in order to provide information of the latest stable version of Waggle to users. Github markdown files placed in our github repositories are used to generate such web pages. This means that contents of the web pages come from the corresponding markdown files. This allows us to maintain our web site by just editing the markdown files and compiling them to make updated web pages.

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

## Deverloper notes

* pandoc uses style.css under __'res'__ folder, which has MIT license.
* Relative links for other web pages (shown only in the file list) or images are re-routed using the path of html files while absolute links are untouched.
* Further information about compilation can be found at [Pandoc](http://pandoc.org)
