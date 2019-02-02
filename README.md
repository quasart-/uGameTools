# TaToGE: TableTop Game Equipment

This project provides a bunch of simple widgets to emulate the common game equipment needed when playing board games or card games : Dice, sandtimers, score counters...

It focuses on simplicity, and on the idea it will be used as a companion during "real" table-top gaming.

## Features

- Widgets for game state display:
  - `Timer` for virtual sand-clock
  - `Counter`
  - `CountDown`/`Sequence` steps follower
- Widgets to generate random:
  - `Dice`
  - `CardDrawer` for draw without replacement (Note that draw *with* replacement can be performed in `Dice` widget by setting `Count` parameter greater than 1.)
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
- Expert mode (json edit) for adding widgets ?
- Parameter for rolling/drawing time

## Build dependency

Needs:
- Qt5
- C++14 compiler
- qmake to generate Makefile, and lrelease to generate translation file
- Imagemagick to render icon files

That means on debian/ubuntu:
```
sudo apt-get install qtbase5-dev qt5-default qttools5-dev-tools imagemagick
lrelease tatoge.pro
./images/render.sh
qmake
make
```

