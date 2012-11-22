#include "Spin.hpp"

#ifndef SPINSPOTS_H_
#define SPINSPOTS_H_

class SpinSpots : public Spin {
public:
  float dim;

  SpinSpots(float x, float y, float s, float d) : Spin(x, y, s) { dim = d; }
  void display();
};

#endif