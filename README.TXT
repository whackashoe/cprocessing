Welcome to the Bright Side
__________________________

The idea is to enable the writing of graphical applications using Processing's simple commands but levered by C++'s superior performance.
I hope that with this project people can use a library that is easy to use yet can take advantage of c's features.
Right now there is just some of the basic drawing and input events ported, yet it is still quite usable.
A sketch creator has been made to help people out who are new to programming.
This project has been forked from http://code.google.com/p/cprocessing



Example
__________________________

//Draw Alien

#include <cprocessing.hpp>
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




Installation Instructions
__________________________


Please make sure you have the following dependencies installed

	libGL
	libGLU
	libglut

libGL and libGLU should be taken care of by graphics drivers such as mesa
freeglut can be found at http://freeglut.sourceforge.net/docs/install.php


Once you have these things installed clone this repository and cd into it

Type "make"
Type "sudo cp cprocessing.hpp /usr/local/include/cprocessing.hpp"
Type "sudo cp objects/libcprocessing.a /usr/local/lib/libcprocessing.a"

If everything worked without errors you can now create a new sketch.



Creating a Sketch
__________________________

cd to sketchbook and then type "./new.sh myfirstsketch"
This will create a new folder in your sketchbook with a main.cpp file and a Makefile
cd to myfirstsketch and type "make"
Now type "./myfirstsketch" and watch the magic ...?
You can edit main.cpp all you like, just type make to compile your changes
(note that not all processing functions are available yet)


License
__________________________

The BSD 2-Clause License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

