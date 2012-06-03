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
~~~~




Installation Instructions
-------------------------

## Linux:

Please make sure you have the following dependencies installed


* libGL
* libGLU
* libglut



1. On debian distributions sudo apt-get install freeglut3-dev  (as a superuser) to install the freeglut dependency
 Most distributions will have freeglut or glut in their respective repositories,
 alternatively freeglut can be found at http://freeglut.sourceforge.net/docs/install.php and installed from source.
2. git clone https://github.com/whackashoe/cprocessing
3. cd cprocessing
4. ./install.sh


## Windows:


1. In order to run cprocessing you must first install MinGW, grab the gui from http://sourceforge.net/projects/mingw/files/Installer/mingw-get-inst/
2. Make sure you select the C++ compiler and the MinGW Developer ToolKit, keep install path space free(default works good)
3. Download freeglut from here: http://files.transmissionzero.co.uk/software/development/GLUT/freeglut-MinGW.zip and unzip it to some directory. Copy freeglut.dll to C:\Windows\System32 or C:\Windows\SystemWOW64 depending on 32 or 64 bit windows.
4. Copy the files from the include directory to MinGW's include directory(default is C:\MinGW\include)
5. Copy the files from the lib directory to MinGW's lib directory(default is C:\MinGW\lib)
6. Open MinGW by Start->Programs->MinGW->MinGW shell
7. clone the repository and cd into it
8. type "make"
9. Copy cprocessing.hpp to MinGW's include directory
10. Copy libcprocessing.a to MinGW's lib directory
11. cd to examples, choose an example and open its Makefile
12. change "-lcprocessing -lglut -lGL -lGLU" to "-lcprocessing -lfreeglut -lglu32 -lopengl32"
12. save the file then type "make" in that directory
13. now type "./(examplename)" without parethesis to open program
14. Your done! That was ridiculous wasn't it?



Creating a Sketch
-----------------

cd to sketchbook and then type "./new.sh myfirstsketch" 
This will create a new folder in your sketchbook with a main.cpp file and a Makefile
cd to myfirstsketch and type "make"
Now type "./myfirstsketch" and watch the magic ...?
You can edit main.cpp all you like, just type make to compile your changes
(note that not all processing functions are available yet)


License
-------

The BSD 2-Clause License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

