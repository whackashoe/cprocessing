#include <cprocessing/cprocessing.hpp>

#ifndef RING_H_
#define RING_H_

class Ring {
public:
  float x, y; // X-coordinate, y-coordinate
  float diameter; // Diameter of the ring
  boolean on; // Turns the display on and off

  Ring();
  
  void start(float xpos, float ypos);
  void grow();
  void display();
};

#endif