# CPP Quest

This is a RPG-style console game for people interested in learning C++. I decided to make this game because LeetCode is cool and semi-gamified but I like RPGs. I have a lot to do to make this game useful to anyone but myself. 
 
## Get started:
### Linux
The following steps have been tested on Ubuntu 

1. Install g++
`sudo apt install build-essential`
2. Install boost libraries 
Run `sudo apt-get install libboost-all-dev`
3. Install cmake: 
Download the latest cmake from github: https://github.com/Kitware/CMake
Run `./boostrap && make && sudo make install`
Depending on your configuration, you may need to install OpenSSL: `sudo apt install libssl-dev`
4. Clone the CPP_Quest source code
5. Build with CMAKE: 

`cd out/build`

`ccmake ../..`

`make`

6. Now you can play the game or customize it in any way you would like!

## Gameplay
For now, this will only be a console app consisting of interview-style read/write input and output operations

## Graphics
Eventually I would like to include a graphics engine but I want to work out the game play and learning system first.

## Development environment and cross-platform issues
The current version was developed on a Windows 10 machine with visual studio using C++17 and has been tested on Ubuntu 20.

## TODO:
### Game Development:
-improve MainCharacter data loading component; 
-create test system
-create system for lesson management
-Generate more lesson XMLs based on the sequence of Stroustrup's Tour of C++
-Create sidequest system
-Create storyline
-Add graphics
