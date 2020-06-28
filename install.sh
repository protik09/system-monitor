#!/bin/bash

sudo apt install qt5-default libprocps-dev -y

# Fix an issue with the qt5 core library
sudo strip --remove-section=.note.ABI-tag /usr/lib/x86_64-linux-gnu/libQt5Core.so.5

# Make the program
qmake && make -j$(nproc)