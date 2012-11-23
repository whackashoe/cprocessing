#ifndef EYE_H_
#define EYE_H_

class Eye {
public:
  int x;
  int y;
  int size;
  float angle;
  
  Eye(int tx, int ty, int ts);

  void update(int mx, int my);
  void display();
};

#endif