#!/usr/bin/env python
from setup_all import *
from setuptools import setup

packages = cloud_packages

namespace_packages = list(set(namespaces) & set(packages))

install_requires = cloud_dependancies

setup(
    packages = packages,
    namespace_packages = namespace_packages,
    install_requires = install_requires,

    name = name,
    version = version,
    description = description,
    author = author,
    author_email = author_email,
    url = url,
    long_description = long_description
)
