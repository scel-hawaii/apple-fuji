# apple-core

Contains some software examples for accessing the Apple weatherbox sensors. 



# Sections

Filename            |   Description
--------            |   -----------
apple-core.ino      |   Main file
apple.h             |   Contains pin settings
sensors.h           |   Header file for sensor functions
sensors.cpp         |   Main functions for accessing sensors on the board


# Build Instructions

1. Download the Arduino IDE. You can do so here: https://www.arduino.cc/en/Main/Software
2. Copy the folders in the repository's library to your Arduino sketchbook directory
    * You can find your sketchbook directory by __opening__ the Arduino IDE and clicking on preferences
3. Restart the Arduino IDE
4. Press verify to compile and verify your code
5. Press upload when you're ready to program your device. 


# Notes on .cpp and .h files

If you're planning to modularize your code (which you should) by separating
your logic into `.cpp` and `.h` files, remember that in addition to adding the
needed libraries to your relevant `.cpp` and `.h` files you **NEED** to include
it into the main `.ino` file as well.

The main `.ino` file (the one with folder-name.ino) is that the Arduino IDE looks
for when it attempts to link everything together. If the relevant headers are not included
in the `.ino` file, you'll get an error when you try to build the project

