#include <cprocessing/cprocessing.hpp>
#include "MRect.hpp"

MRect::MRect(int iw, float ixp, float ih, float iyp, float id, float it) {
  w = iw;
  xpos = ixp;
  h = ih;
  ypos = iyp;
  d = id;
  t = it;
}

void MRect::move (float posX, float posY, float damping) {
  float dif = ypos - posY;
  if (abs(dif) > 1) {
    ypos -= dif/damping;
  }
  dif = xpos - posX;
  if (abs(dif) > 1) {
    xpos -= dif/damping;
  }
}

void MRect::display() {
  for (int i=0; i<t; i++) {
    rect(xpos+(i*(d+w)), ypos, w, height*h);
  }
}