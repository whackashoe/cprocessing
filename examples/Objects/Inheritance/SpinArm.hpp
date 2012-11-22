#include "Spin.hpp"

#ifndef SPINARM_H_
#define SPINARM_H_

class SpinArm: public Spin {
public:
  SpinArm(float x, float y, float s) : Spin(x, y, s) {}
  void display();
};

#endif