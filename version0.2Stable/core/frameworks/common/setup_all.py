#!/usr/bin/env python
from setuptools import setup

# Could be useful to set up this
# files = ["some file"]

###############################################################################
# Cloud Specifics
###############################################################################

cloud_dependancies = ['pika==0.9.8']
cloud_packages = ['waggle', 'waggle.common', 'waggle.cloud']


###############################################################################
# Guest Node Specific things
###############################################################################

guest_node_dependancies = []
guest_node_packages = ['waggle', 'waggle.common', 'waggle.device',
        'waggle.device.common', 'waggle.device.guest_node']


###############################################################################
# Node Controller Specific things
###############################################################################

node_controller_dependancies = []
node_controller_packages = ['waggle', 'waggle.common', 'waggle.device', 
        'waggle.device.common', 'waggle.device.node_controller']


###############################################################################
# General Settings
###############################################################################

name = "waggle"
namespaces = ['waggle', 'waggle.device']

version = "1"
description = "WAggLE Library"
author = "WAggLE Team"
author_email = "r@anl.gov"
url = "www.mcs.anl.gov/~brsquared/"
long_description = """Sensor to cloud data acquisition system."""


###############################################################################

if __name__ == "__main__":
    packages = list(set(cloud_packages) | 
                    set(guest_node_packages) | 
                    set(node_controller_packages))

    namespace_packages = list(set(namespaces) & set(packages))

    install_requires = list(set(cloud_dependancies) | 
                            set(guest_node_dependancies) | 
                            set(node_controller_dependancies))

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
