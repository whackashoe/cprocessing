#ifndef SPOT_H_
#define SPOT_H_

class Spot {
public:
  float x, y, radius;

  Spot();
  Spot(float xpos, float ypos, float r);

  void display();
};

#endif