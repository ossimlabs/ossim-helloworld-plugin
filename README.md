# Welcome to the Hello World Plugin
This plugin documents how to setup a vanilla plugin for the OSSIM framework and how to build from an installed OSSIM devel package.  For the instructions that follow we will assume that the ossim-devel RPMS for yum installation was installed but if you have built ossim and did a make install to an installation directory that should work as well.  For simplicity we will use a the following variables

* **`OSSIM_INSTALL_PREFIX`** Specifies the install prefix that the ossim libraries were installed to.  This must be the full devel that include the CMakeModules during the installation process.  If you are using the yum install then this will be in /usr/share/ossim/<ossim-version-number>/CMakeModules
* **`OSSIM_VERSION`** Specifies the current ossim version to use.  For this documentation we will use 1.9.0 as an example version

# Build the plugin

```
git clone https://github.com/ossimlabs/ossim-helloworld-plugin.git
cd ossim-helloworld-plugin 
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_MODULE_PATH=/usr/share/ossim/1.9.0/CMakeModules
make install
```

Make sure you set the version number to the version of OSSIM that is installed.

