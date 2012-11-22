#ifndef MRECT_H_
#define MRECT_H_

class MRect 
{
public:
  int w; // single bar width
  float xpos; // rect xposition
  float h; // rect height
  float ypos ; // rect yposition
  float d; // single bar distance
  float t; // number of bars
 
  MRect(int iw, float ixp, float ih, float iyp, float id, float it);
 
  void move (float posX, float posY, float damping);
  void display();
};

#endif