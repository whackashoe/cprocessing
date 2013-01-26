cprocessing::Welcome to the Bright Side
=======================================

The idea is to enable the writing of graphical applications using Processing's simple commands but levered by C++'s superior performance.
I hope that with this project people can use a library that is easy to use yet can take advantage of c's features and library set.
Right now there is just some of the basic drawing and input events ported, yet it is still quite usable.
A sketch creator has been made to help people out who are new to programming.
This project has been forked from http://code.google.com/p/cprocessing



Example
-------

~~~~.c
//Draw Alien

#include <cprocessing/cprocessing.hpp>
using namespace cprocessing;

void setup(){
  size(200,200);
}
void draw(){
  rectMode(CENTER);
  rect(100,100,20,100);
  ellipse(100,70,60,60);
  ellipse(81,70,16,32); 
  ellipse(119,70,16,32); 
  line(90,150,80,160);
  line(110,150,120,160);
}
~~~~




Installation Instructions
-------------------------

## Linux:

Please make sure you have the following dependencies installed


* libGL
* libGLU
* libglfw
* libmagic++
* libGLEW
* libFreeImage

1. On ubuntu distributions: sudo apt-get install libglu1-mesa-dev libglfw-dev libglew1.6-dev libfreeimage-dev
2. git clone https://github.com/whackashoe/cprocessing
3. cd cprocessing
4. ./install.sh



Creating a Sketch
-----------------

1. cd to sketchpad
2. then type `./new.sh myfirstsketch`, this will create a new folder in your sketchpad
3. cd to myfirstsketch and type `make`. If this doesn't work you need to fix your installation.
4. Now type `./sketch` If everything is working correctly a blank window will open
5. Edit away partner.
