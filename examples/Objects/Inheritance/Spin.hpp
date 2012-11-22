#ifndef SPIN_H_
#define SPIN_H_

class Spin {
public:
  float x, y, speed;
  float angle;
  
  Spin(float xpos, float ypos, float s);
  void update();
};

#endif