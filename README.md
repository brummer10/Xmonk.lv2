# Xmonk.lv2
A LV2 toy

![xmonk](https://github.com/brummer10/Xmonk.lv2/raw/master/xmonk.png)


## Features

- a simple sound generator to have some fun with.


## Dependencys

- libcairo2-dev
- libx11-dev
- lv2-dev

## Build for Linux
- git submodule init
- git submodule update
- make
- make install # will install into ~/.lv2 ... AND/OR....
- sudo make install # will install into /usr/lib/lv2

## Build for MSWindows

To build libxputty cross compiled on Linux for MSWindows the easiest way is to use 

[PawPaw](https://github.com/DISTRHO/PawPaw) 

to set up the needed dependencies to build for MSWindows.

Install wine and the mingw g++ and gcc compiler packages (w64-x86-64, w64-i686)

from your distribution repository

and then clone the [PawPaw](https://github.com/DISTRHO/PawPaw) repository 

`git clone https://github.com/DISTRHO/PawPaw`

and build the windows build environment.

`cd PawPaw`

`./bootstrap-plugins.sh win64`

That may take a while. You only need to do that once st all.

When done, go to the top Directory of Xmonk.lv2

and run

`./libxputty/build.sh windows`

that's it.
