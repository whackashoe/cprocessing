#include "Egg.hpp"
#include "Ring.hpp"

#ifndef EGGRING_H_
#define EGGRING_H_

class EggRing {
public:
  Egg * ovoid;
  Ring * circle;

  EggRing(float x, float y, float t, float sp);
  void transmit();
};

#endif