#include "EggRing.hpp"

EggRing::EggRing(float x, float y, float t, float sp) {
  circle = new Ring();
  ovoid = new Egg(x, y, t, sp);
  circle->start(x, y - sp/2);
}

void EggRing::transmit() {
  ovoid->wobble();
  ovoid->display();
  circle->grow();
  circle->display();
  if (circle->on == false) {
    circle->on = true;
  }
}