# TaToGE

This project provides a bunch of simple widgets to emulate the common game equipment needed when playing board games or card games : Dice, sandtimers, score counters...

It focuses on simplicity, and on the idea it will be used as a companion during "real" table-top gaming.

## Features

- Virtual board-game tools:
  - SandTimer
  - Counter
  - Dice
  - Sequence/CountDown follower
- Template file loading (in json format)


# Developer guide

## Improvement ideas

- New widgets:
   - Score table
   - "Go" signal
- Add sounds on events
- General reset button
- Tools dynamic delete/order
- Game status/template export
- Dice graphics with dots
- lock mode parameter (to hide admin menus)
- Expert mode (json edit) for adding widgets

## TODO

- improve "add widget" dialog
- make icons
    - https://commons.wikimedia.org/wiki/File:Terninger.jpg
    - https://standards.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html

## Build command

Needs Qt5 and C++14 compiler.

For debian/ubuntu:
```
sudo apt-get install qtbase5-dev qt5-default
qmake
make
```

For windows build on debian/ubuntu through [MXE](https://mxe.cc/):
```
sudo apt-get install \
    autoconf \
    automake \
    autopoint \
    bash \
    bison \
    bzip2 \
    flex \
    g++ \
    gettext \
    git \
    gperf \
    intltool \
    libc6-dev-i386 \
    libgdk-pixbuf2.0-dev \
    libltdl-dev \
    libssl-dev \
    libtool-bin \
    libxml-parser-perl \
    lzip \
    make \
    openssl \
    p7zip-full \
    patch \
    perl \
    pkg-config \
    python \
    ruby \
    sed \
    unzip \
    wget \
    xz-utils
sudo apt-get install g++-multilib

git clone https://github.com/mxe/mxe.git
cd mxe
make qtbase

### Will generate : ../mxe/usr/bin/i686-w64-mingw32.static-qmake-qt5

```

