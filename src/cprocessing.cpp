/*
 * graphics.cpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */
#include "cprocessing.hpp"


/// This will link with the client's functions
extern void draw();
extern void setup();
extern void mousePressed();
extern void mouseReleased();
extern void mouseMoved();
extern void mouseDragged();
extern void keyPressed();
extern void keyReleased();

using namespace cprocessing;


namespace cprocessing {

  Style baseStyle;
  bool mouseRecordFlag = true; // When to record or not the mouse position
	//
  // Global variables
	//

	int mouseX = 0;  ///< Mouse x coordinate
	int mouseY = 0;  ///< Mouse y coordinate
	int pmouseX = 0;  ///< Previous mouse x coordinate
	int pmouseY = 0;  ///< Previous mouse y coordinate
	bool mousePressed = false; ///< Whether any mouse button is pressed
	int mouseButton = LEFT; ///< Which button is pressed
	bool keyPressed = false; ///< Whether a key was pressed
	unsigned char key; ///< Which (ASCII) key was pressed
	int keyCode;   ///< Code for the last pressed key

	int width;     ///< window width
	int height;    ///< window height
	
	bool looping = true;   ///redisplay if true

	unsigned config = HALF_PIXEL_SHIFT | Y_DOWN; ///< Configuration flags

	int framerate = 60; ///< Frames per second
  int frameCount = 0;
	int initialized = false; 	///< Whether or not initialization of glut took place

  std::vector<Style> styles;
  PixelColorBuffer pixels;
  PImage screenBuffer;
	//color strokeColor (0,0,0);     ///< Line drawing color
	//color fillColor   (255,255,255);   ///< Area drawing color

	/// 
	/// Global OpenGL initialization code. Should be called at least once when screen is established
	///
    static void init () {
      // Enable depth buffer
      glEnable(GL_DEPTH_TEST);

      // Make it possible to overwrite pixels
      glDepthFunc(GL_LEQUAL);

      glShadeModel(GL_SMOOTH);

      glEnable(GL_MULTISAMPLE_ARB);

      // Helps when drawing in 3D with wireframe superimposed on the filled faces
      glPolygonOffset (1., -1.);

      // Cope with scaling transformations
      glEnable(GL_RESCALE_NORMAL);
      glEnable(GL_NORMALIZE);

      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      // Disable the default additional ambient component
      float ambient [] = {0, 0, 0, 1};
      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

      // By default, y is flipped, so front is clockwise
      glFrontFace(GL_CW);

      // Make it possible to set material properties by using glcolor
      glEnable(GL_COLOR_MATERIAL);
      glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
      glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
	}    	


    /// This is called for each frame
    static void display () {
        // Restore default state
        camera();
        perspective();
        noLights();
        ::draw();
        mouseRecordFlag = true;

        // End by swapping front and back buffers
        glutSwapBuffers() ;
    }

    /// Called whenever window geometry is changed.
    /// @param w New width of the window.
    /// @param h New height of the window.
    static void reshape (int w, int h)
    {
        glViewport(0,0,w,h);

        width = w;
        height = h;

        // Initialize OPENGL modes
        init();
        loadPixels();
    }

    /// The refresh function is called periodically to redisplay
    static void refresh (int) {
        if(looping) {
          frameCount++;
        	glutPostRedisplay();
        	glutTimerFunc (1000/framerate, refresh, 0);
        }
    }

    void redraw() {
      frameCount++;
      display();
    }

    void loadPixels() {
      glFlush();
      if(screenBuffer.texturebuffer) delete screenBuffer.texturebuffer;
      screenBuffer.texturebuffer = new unsigned char[width*height*4];
      glReadPixels (0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE , (void*) screenBuffer.texturebuffer);
      screenBuffer.width = width;
      screenBuffer.height = height;
      screenBuffer.updatePixels();
    }

    //FIXME:: I seem to work when tested via prints here, but when calling outside of lib I always return 0 :(
    void loadPixels(int x, int y, int w, int h) {
      /*if (!backbuffer) allocbuffer();
      glFlush();

      //we copy the section here into a temp buffer then move it into the main backbuffer accordingly
      char tbuffer[w*h*4];
      glReadPixels (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE , tbuffer);

      for(int i=0, cx=x, cy=y; i<w*h; i++) {
        if(i % w == 0) {
          cx = 0;
          cy++;
        }
        backbuffer[(cy*width)+cx] = tbuffer[i];

        cx++;
      }

      screenBuffer.loadPixels();*/
    }

    void updatePixels() {
      image(screenBuffer, 0, 0, width, height);
    }

    color get(int x, int y) {
      return screenBuffer.get(x, y);
    }

    ArrayList<color> get(int x, int y, int w, int h) {
      ArrayList<color> v;

      for(int yc = y; yc<y+h; yc++) {
        for(int xc = x; xc<x+h; xc++) {
          v.add(screenBuffer.get(x, y));
        }
      }

      return v;
    }

    void set(int x, int y, const color& c) {
      screenBuffer.set(x, y, c);
    }

    void set(int x, int y, int w, int h, const color& c) {
      for(int yc = y; yc<y+h; yc++) {
        for(int xc = x; xc<x+h; xc++) {
          screenBuffer.set(x, y, c);
        }
      }
    }

     color blendColor(const color& a, const color& b, unsigned mode) {
        assert (mode == REPLACE || mode == BLEND || mode == ADD || mode == SUBTRACT || mode == DARKEST || mode == LIGHTEST || mode == DIFFERENCE || mode == EXCLUSION || mode == MULTIPLY || mode == SCREEN || mode == OVERLAY || mode == HARD_LIGHT || mode == SOFT_LIGHT || mode == DODGE || mode == BURN);
        //TODO:: finish blend modes
        switch(mode) {
            case REPLACE:
                return color(b.rgba[0], 
                             b.rgba[1], 
                             b.rgba[2], 
                             b.rgba[3]);
                break;
            case BLEND:
                return color((a.rgba[0]+b.rgba[0])/2, 
                             (a.rgba[1]+b.rgba[1])/2, 
                             (a.rgba[2]+b.rgba[2])/2, 
                             (a.rgba[3]+b.rgba[3])/2);
                break;
            case ADD:
                return color(min(a.rgba[0]+b.rgba[0], 255),
                             min(a.rgba[1]+b.rgba[1], 255), 
                             min(a.rgba[2]+b.rgba[2], 255), 
                             min(a.rgba[3]+b.rgba[3], 255));
                break;
            case SUBTRACT:
                return color(0, 0, 0, 255);
                break;
            case DARKEST:
                return color(0, 0, 0, 255);
                break;
            case LIGHTEST:
                return color(0, 0, 0, 255);
                break;
            case DIFFERENCE:
                return color(0, 0, 0, 255);
                break;
            case EXCLUSION:
                return color(0, 0, 0, 255);
                break;
            case MULTIPLY:
                return color(0, 0, 0, 255);
                break;   
            case SCREEN:
                return color(0, 0, 0, 255);
                break;
            case OVERLAY:
                return color(0, 0, 0, 255);
                break;
            case HARD_LIGHT:
                return color(0, 0, 0, 255);
                break;
            case SOFT_LIGHT:
                return color(0, 0, 0, 255);
                break;
            case DODGE:
                return color(0, 0, 0, 255);
                break;
            case BURN:
                return color(0, 0, 0, 255);
                break;
        }

        return color();
    }

    color lerpColor(const color& a, const color& b, double amt) {
      return color(lerp(a.rgba[0], b.rgba[0], amt), 
                   lerp(a.rgba[1], b.rgba[1], amt), 
                   lerp(a.rgba[2], b.rgba[2], amt), 
                   lerp(a.rgba[3], b.rgba[3], amt));
    }

    /// Called whenever mouse moves
    static void mousemotion (int x, int y) {
      if (mouseRecordFlag){
         pmouseX = mouseX;
         pmouseY = mouseY;
         mouseX = ((x < 0) ? 0 : x);
         mouseY = ((y < 0) ? 0 : y);
         mouseRecordFlag = false;
      }
      ::mouseMoved();
    	if (mousePressed) {
    		::mouseDragged();
    	}
    }

    /// Called whenever mouse button is pressed
    static void mouse (int button, int state, int x, int y) {
       if (mouseRecordFlag){
         pmouseX = mouseX;
         pmouseY = mouseY;
         mouseX = x;
         mouseY = y;
         mouseRecordFlag = false;
       }

       mousePressed = state == GLUT_DOWN;
  
       if (button == GLUT_LEFT_BUTTON) {
          mouseButton = LEFT;
       } else if (button == GLUT_RIGHT_BUTTON) {
          mouseButton = RIGHT;
       } else {
          mouseButton = CENTER;
       }
       if (mousePressed) {
          ::mousePressed();
       }
       else {
          ::mouseReleased();
       }
    }

    /// Called whenever a key is pressed
    static void keyboard (unsigned char ch, int x, int y) {
    	keyPressed = true;
    	key = ch;
    	keyCode = ch;
    	::keyPressed();
    }

    /// Called whenever a key is released
    static void keyboardup (unsigned char ch, int x, int y) {
    	keyPressed = false;
      key = ch;
      keyCode = ch;
    	::keyReleased();
    }

    /// Called whenever a special key is pressed
    static void special (int ch, int x, int y) {
    	keyPressed = true;
    	key = CODED;
    	keyCode = 0;
    	switch (ch) {
			case GLUT_KEY_F1:
			case GLUT_KEY_F2:
			case GLUT_KEY_F3:
			case GLUT_KEY_F4:
			case GLUT_KEY_F5:
			case GLUT_KEY_F6:
			case GLUT_KEY_F7:
			case GLUT_KEY_F8:
			case GLUT_KEY_F9:
			case GLUT_KEY_F10:
			case GLUT_KEY_F11:
			case GLUT_KEY_F12:
				keyCode = ch + F1 - GLUT_KEY_F1;
				break;
			case GLUT_KEY_LEFT:
				keyCode = LEFT;
				break;
			case GLUT_KEY_UP:
				keyCode = UP;
				break;
			case GLUT_KEY_RIGHT:
				keyCode = RIGHT;
				break;
			case GLUT_KEY_DOWN:
				keyCode = DOWN;
				break;
			case GLUT_KEY_PAGE_UP:
				keyCode = PAGEUP;
				break;
			case GLUT_KEY_PAGE_DOWN:
				keyCode = PAGEDOWN;
				break;
			case GLUT_KEY_HOME:
				keyCode = HOME;
				break;
			case GLUT_KEY_END:
				keyCode = END;
				break;
			case GLUT_KEY_INSERT:
				keyCode = INSERT;
				break;
    	}
    	::keyPressed();
    }


    /// Called whenever a special key is released
    static void specialup (int ch, int x, int y) {
    	keyPressed = false;
    	::keyReleased();
    }

    /// Sets up a window of the given size
    /// @param w Desired window width in pixels.
    /// @param h Desired window height in pixels.
    /// @param name Desired window title.
    void size (unsigned w, unsigned h, const char* name) {
    	if (initialized) {
    		glutReshapeWindow (w, h);
    		glutSetWindowTitle (name);
    	} else {
			glutInitWindowSize (w, h);
			width = w;
			height = h;
			glutCreateWindow (name);
			glutReshapeFunc(reshape);
			glutDisplayFunc(display);
			glutMotionFunc (mousemotion);
			glutPassiveMotionFunc (mousemotion);
			glutMouseFunc (mouse);
			glutKeyboardFunc (keyboard);
			glutKeyboardUpFunc (keyboardup);
			glutSpecialFunc(special);
			glutSpecialUpFunc(specialup);
			initialized = true;
      glewInit();
    	}

    }

    /// Sets line color
    /// @param c New line color
    void stroke (const color& c) {
        styles[styles.size()-1].strokeColor = color(c);
    }

    /// Sets area color
    /// @param c New area color
    void fill (const color& c) {
      styles[styles.size()-1].fillColor = color(c);
    }

    /// Sets line / point width
    /// @param weight: New breadth of line in pixels
    void strokeWeight (int weight) {
        //TODO:: styles[styles.size()-1].strokeWeight = weight;
        glLineWidth (weight);
        glPointSize (weight);
    }


    /// Clear the window with a background color
    /// @param c: background color
    void background (const color& c) {
        glClearColor (c.rgba[0] * (1.0/255),
                      c.rgba[1] * (1.0/255),
                      c.rgba[2] * (1.0/255),
                      c.rgba[3] * (1.0/255));
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    /// Clear the window with a background image
    /// @param img: background image
    void background (PImage& img) {
        background(color(0));
        image(img, 0, 0, width, height);
    }

    void background (PImage * img) {
        background(color(0));
        image(img, 0, 0, width, height);
    }

    /// Sets state so that lines are rendered antialiased.
    void smooth() {
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    }

    /// Sets state so that lines are rendered quickly.
    void noSmooth() {
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

    PImage createImage(int width, int height, int type) { 
        return PImage(width, height, type);
    }

    int second() {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer [3];
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      strftime (buffer,3,"%S",timeinfo);
      return atoi(buffer);
    }


    int minute() {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer [3];
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      strftime (buffer,3,"%M",timeinfo);
      return atoi(buffer);
    }


    int hour() {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer [3];
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      strftime (buffer,3,"%H",timeinfo);
      return atoi(buffer);
    }


    int day() {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer [3];
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      strftime (buffer,3,"%d",timeinfo);
      return atoi(buffer);
    }

    int month() {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer [3];
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      strftime (buffer,3,"%m",timeinfo);
      return atoi(buffer);
    }

    int year() {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer [5];
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      strftime (buffer,5,"%Y",timeinfo);
      return atoi(buffer);
    }

    const char * loadBytes(const char * src) {
      int length;
      char * buffer;

      std::ifstream is;
      is.open(src, std::ios::binary);
      is.seekg (0, std::ios::end);
      length = is.tellg();
      is.seekg (0, std::ios::beg);
      buffer = new char [length];
      is.read (buffer,length);
      is.close();

      return buffer;
    }

    ArrayList<String> loadStrings(const char * src) {
      std::ifstream f(src);
      std::string line;
      ArrayList<String> strings;

      while(std::getline(f, line)) {
          strings.add(String(line));
      }

      return strings;
    }
    ArrayList<String> loadStrings(String src) { return loadStrings(src.toCharArray()); }


    
    void pushStyle() {
      Style * newStyle = new Style;
      styles.push_back(*newStyle);
    }

    void popStyle() {
      if(styles.size() > 1) styles.pop_back();
      else                  printerr("cannot have more popStyles() than pushStyles()");
    }


    String nf(int n, int d) {
      char * buf = new char[d];
      sprintf(buf,"%d",n);
      String t(buf);
      String b = "";

      if(t.length() > d) {
        //FIXME: cut off end e.g. make 124567 with d=4 1245
      }

      for(int i=t.length(); i < d; i++) {
        b += "0";
      }

      String r = b + t;
      return r;
    }


    /// Initializes and runs the application main event loop
    void run() {
		  int argc = 0;
		  char **argv = 0;
      glutInit(&argc, argv);
	    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	    glutTimerFunc (1000/framerate, refresh, 0);
      styles.push_back(baseStyle);
      bezierDetail(50);
      ellipseDetail(50);
    	sphereDetail(30,30);
      stroke(0);
      fill(255);

      strokeWeight(1);
      colorMode(RGB);
      rectMode(CORNER);
      ellipseMode(CENTER);

      pixels.setBuffer(screenBuffer.texturebuffer);

    	::setup();
      glutMainLoop();
    }
}

