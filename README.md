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
* libglut
* libmagic++
* libGLEW
* libFreeImage


1. On ubuntu distributions: sudo apt-get install libglu1mesa-dev freeglut3-dev libmagic++-dev libglew1.6-dev libfreeimage-dev
2. git clone https://github.com/whackashoe/cprocessing
3. cd cprocessing
4. ./install.sh


## Windows:

(WINDOWS COMPILATION AND WORKABILITY IS UNKNOWN)
The following directions may no longer be correct. Well, actually they definitely aren't. I need to find a windows machine
to test on and make sure cprocessing compiles and runs. If you know what you are doing it shouldn't be too hard- if you don't I suggest you 
file multiple reports to motivate me.


1. In order to run cprocessing you must first install MinGW, grab the gui from http://sourceforge.net/projects/mingw/files/Installer/mingw-get-inst/
2. Make sure you select the C++ compiler and the MinGW Developer ToolKit, keep install path space free(default works good)
3. Download freeglut from here: http://files.transmissionzero.co.uk/software/development/GLUT/freeglut-MinGW.zip and unzip it to some directory. Copy freeglut.dll to C:\Windows\System32 or C:\Windows\SystemWOW64 depending on 32 or 64 bit windows.
4. Download glew from here: http://glew.sourceforge.net/ and unzip it into some directory.
5. Copy the files from the include directorys to MinGW's include directory(default is C:\MinGW\include)
6. Copy the files from the lib directorys to MinGW's lib directory(default is C:\MinGW\lib)
7. Open MinGW by Start->Programs->MinGW->MinGW shell
8. clone the repository and cd into it
9. type "make"
10. Copy cprocessing.hpp to MinGW's include directory
11. Copy libcprocessing.a to MinGW's lib directory
12. cd to examples, choose an example and open its Makefile
13. change "-lcprocessing -lglut -lGL -lGLU" to "-lcprocessing -lfreeglut -lglu32 -lopengl32 -lglew32"
14. save the file then type "make" in that directory
15. now type `./(examplename)` to open program
16. Your done! That was ridiculous wasn't it?



Creating a Sketch
-----------------

1. cd to sketchpad
2. then type `./new.sh myfirstsketch`, this will create a new folder in your sketchpad
3. cd to myfirstsketch and type `make`. If this doesn't work you need to fix your installation.
4. Now type `./sketch` and watch the magic ...? If everything is working correctly a blank window will open
5. You can edit main.cpp all you like, just type make to compile your changes
6. You can also type "./debug.sh" to help debug your script if it compiles yet crashes when it runs (requires GNU Debugger or GDB)
