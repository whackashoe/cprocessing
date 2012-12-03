#ifndef MODULE_H_
#define MODULE_H_

class Module {
  public:   
  int xOffset;
  int yOffset;
  float x, y;
  int unit;
  int xDirection;
  int yDirection;
  float speed; 
  
  // Contructor
  Module();
  Module(int xOffsetTemp, int yOffsetTemp, int xTemp, int yTemp, float speedTemp, int tempUnit); 
  
  // Custom method for updating the variables
  void update();
  // Custom method for drawing the object
  void draw();
};

#endif
