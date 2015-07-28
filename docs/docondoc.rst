Documentation Structure
=======================

Waggle is documented using Sphinx_. Within the git repo, there is a docs directory that contains
all documentation files. The general structure of the documentation follows the structure of the
documentation page, with the main sections of the documentation being broken down into directories
and subdirectories, each of which has a main table of contents file with the same name as the directory
in which it resides. Notable oddities in the documentaion include the fact that the C files for the 
Waggle system manager are run through a quick script to generate their rst files, and several source files
are copied into the docs directory to allow autodoc to read them. To rebuild the documentation, 
run `make clean` from the docs directory, and then `make html` to build the site, which can then be found
in docs/_build/html.

.. _Sphinx: http://sphinx-doc.org/