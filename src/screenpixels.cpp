#include "cprocessing.hpp"

using namespace cprocessing;
namespace cprocessing {

  void loadPixels() {
    glFlush();
    if(screenBuffer.texturebuffer) delete screenBuffer.texturebuffer;
    screenBuffer.texturebuffer = new unsigned char[width*height*4];
    glReadPixels (0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE , (void*) screenBuffer.texturebuffer);
    screenBuffer.width = width;
    screenBuffer.height = height;
    screenBuffer.updatePixels();
  }

  //FIXME:: I seem to work when tested via prints here, but when calling outside of lib I always return 0 :(
  void loadPixels(int x, int y, int w, int h) {
    /*if (!backbuffer) allocbuffer();
    glFlush();

    //we copy the section here into a temp buffer then move it into the main backbuffer accordingly
    char tbuffer[w*h*4];
    glReadPixels (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE , tbuffer);

    for(int i=0, cx=x, cy=y; i<w*h; i++) {
      if(i % w == 0) {
        cx = 0;
        cy++;
      }
      backbuffer[(cy*width)+cx] = tbuffer[i];

      cx++;
    }

    screenBuffer.loadPixels();*/
  }

  void updatePixels() {
    image(screenBuffer, 0, 0, width, height);
  }

  color get(int x, int y) {
    return screenBuffer.get(x, y);
  }

  ArrayList<color> get(int x, int y, int w, int h) {
    ArrayList<color> v;

    for(int yc = y; yc<y+h; yc++) {
      for(int xc = x; xc<x+h; xc++) {
        v.add(screenBuffer.get(x, y));
      }
    }

    return v;
  }

  void set(int x, int y, const color& c) {
    screenBuffer.set(x, y, c);
  }

  void set(int x, int y, int w, int h, const color& c) {
    for(int yc = y; yc<y+h; yc++) {
      for(int xc = x; xc<x+h; xc++) {
        screenBuffer.set(x, y, c);
      }
    }
  }

}