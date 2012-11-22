#ifndef EGG_H_
#define EGG_H_

class Egg {
public:
  float x, y; // X-coordinate, y-coordinate
  float tilt; // Left and right angle offset
  float angle; // Used to define the tilt
  float scalar; // Height of the egg

  Egg(float xpos, float ypos, float t, float s);

  void wobble();
  void display();
};

#endif
