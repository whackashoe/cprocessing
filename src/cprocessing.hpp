/*
 * cprocessing.hpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#ifndef CPROCESSING_HPP_
#define CPROCESSING_HPP_
#include <cmath>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <FreeImage.h>

#include "color.hpp"
#include "pixelcolorbuffer.hpp"
#include "pimage.hpp"
#include "pvector.hpp"
#include "snoise.hpp"
#include "pnoise.hpp"
#include "style.hpp"
#include "arraylist.hpp"
#include "hashmap.hpp"
#include "string.hpp"
#include "pshader.hpp"

//guard, if these are defined they will break windows compilation
#ifdef RADIUS
#undef RADIUS
#endif

#ifdef DELETE
#undef DELETE
#endif


typedef bool boolean;

namespace cprocessing {

	//
	// Global types
	//

	/// Used to test keys
	
	enum { CODED = 255, RETURN = '\r', ENTER = '\n',
		   ESC = 27, TAB = '\t', DELETE = 127
	};

	/// Other constants
	enum { F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		   UP, DOWN, LEFT, RIGHT, CENTER, PAGEUP, PAGEDOWN, HOME, END, INSERT,
		   RADIUS, CORNER, CORNERS
	};

	/// Configuration flags
	enum {
		HALF_PIXEL_SHIFT = 0,    // Whether to shift vertex coordinates by half a pixel (false by default, true makes images slide).
		Y_DOWN           = 1<<1, // Whether to flip the y axis so it points down, rather than up (true by default).
		BACK_BUFFER		 = 1<<2  // Whether to use a backup buffer which is copied every frame in order to effect a stable drawing
		                         // canvas which is maintained between frames (true by default, but should be disabled for speed).
	};

	/// Shape constants
	typedef enum {
		POINTS, LINES, LINE_LOOP, LINE_STRIP, TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP, POLYGON
	} ShapeMode;


	/// Parameter for the endShape function
	typedef enum {
		OPEN = 0, CLOSE = 1
	} ShapeClose;
	

	


	//============================================================================
	//
	// Global variables (defined in file cprocessing.cpp)
	//
	extern int mouseX;  		/**< Mouse x coordinate*/
	extern int mouseY;  		/**< Mouse y coordinate*/
	extern int pmouseX; 		/**< Previous mouse x coordinate*/
	extern int pmouseY; 		/**< Previous mouse y coordinate*/
	extern bool mousePressed; 	/**< Whether any mouse button is pressed*/
	extern int mouseButton; 	/**< Which button is pressed*/
	extern bool keyPressed; 	/**< Whether a key was pressed*/
	extern unsigned char key; 	/**< Which (ASCII) key was pressed*/
	extern int keyCode; 		/**< Code for the last pressed key*/
	extern int width;		 	/**< window width*/
	extern int height; 			/**< window height*/
	extern bool looping;    	/**< true makes display call itself*/
	extern unsigned config; 	/**< configuration flags*/
	extern int framerate; 		/**< Frames per second*/
    extern int frameCount; 		/**< frames since start*/
	extern std::vector<Style> styles; /**< Stack of styles*/
	extern PixelColorBuffer pixels; /**< virtual array of pixels to get and put from (operated thru backbuffer) */
	extern PImage screenBuffer; // ^^
	extern int initialized; 	//glut initialized yet


	//===========================================================================
	//
	// Some math utility functions and constants
	//

    const double PI = 3.14159265358979323846;	/**< PI   */
	const double TWO_PI = 2*PI;					/**< PI*2 */
	const double HALF_PI = PI/2;				/**< PI/2 */
	const double QUARTER_PI = PI/4;				/**< PI/4 */

	/**Updates pixels you have saved into buffer */
	void updatePixels();

	/**Loads all the pixels on the screen into buffer*/
	void loadPixels();

	/**Loads a group of colors from the screen from specific coordinate and width/height into buffer
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param w amount of pixels to grab to the right of x
     * @param h amount of pixels to grab to the right of y*/
	void loadPixels(int x, int y, int w, int h);

	/**Grabs a color from the screen at a specific coordinate, must call loadPixels() first
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @return color at that place*/
	color get(int x, int y);

	/**Grabs a group of colors from the screen from specific coordinate and width/height, must call loadPixels() first
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param w amount of pixels to grab to the right of x
     * @param h amount of pixels to grab to the right of y
     * @return vector of colors grabbed*/
	ArrayList<color> get(int x, int y, int w, int h);
	
	/**Sets a pixel at coordinates to specific color
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param c color to set*/
	void set(int x, int y, const color& c);

	/**Sets a group of pixels at coordinates to specific color
	 * @param x any number between 0 and width
     * @param y any number between 0 and height
     * @param w amount of pixels to set to the right of x
     * @param h amount of pixels to set to the right of y
     * @param c color to set*/
	void set(int x, int y, int w, int h, const color& c);

	/**Calculates absolute value of a number
     * @param a any number
     * @return positive number*/
	template<class T>
	inline T abs(const T& a) { return a<0 ? a*-1 : a; }
	

	//TODO::all of the templates return the type of double
	//FIXME:: this is to prevent issues where a char and two doubles are put in with a char being the result
	//this isn't ideal for ints however, so there should be a better way

	/**Calculates minimum between two numbers
     * @param a any number
     * @param b any number
     * @return smaller of the two numbers*/
	template<class T, class U>
	inline double min(const T& a, const U& b) { return a<b ? a : b; }
	
	/**Calculates maximum between two numbers
     * @param a any number
     * @param b any number
     * @return larger of the two numbers*/
	template<class T, class U>
	inline double max(const T& a, const U& b) { return a>b ? a : b; }
	
	/**Calculates minimum between three numbers
     * @param a any number
     * @param b any number
     * @param c any number
     * @return smallest of the three numbers*/
	template<class T, class U, class V>
	inline double min(const T& a, const U& b, const V& c) { return a<b ? min(a,c) : min(b,c); }
	
	/**Calculates maximum between three numbers
     * @param a any number
     * @param b any number
     * @param c any number
     * @return largest of the three numbers*/
	template<class T, class U, class V>
	inline double max(const T& a, const U& b, const V& c) { return a>b ? max(a,c) : max(b,c); }
	
	/**Constrain value to a certain range
     * @param a any number
     * @param minv minimum
     * @param maxv maximum
     * @return a if a < c && a > b or b if a < b or c if a > c*/
	template<class T, class U, class V>
	inline T constrain(const T& a, const U& minv, const V& maxv) { return min(maxv,max(minv,a)); }
	
	/**Calculates magnitude of 2d vector
     * @param a any number
     * @param b any number
     * @return magnitude of vector*/
	inline double mag (double a, double b) { return sqrt(a*a+b*b); }
	
	/**Calculates magnitude of 3d vector
     * @param a any number
     * @param b any number
     * @param c any number
     * @return magnitude of vector*/
	inline double mag (double a, double b, double c) { return sqrt(a*a+b*b+c*c); }
	
	/**Calculates distance between 2 2D points
     * @param x1 point 1 x coordinate
     * @param y1 point 1 y coordinate
     * @param x2 point 2 x coordinate
     * @param y2 point 2 y coordinate
     * @return distance between points*/
	inline double dist (double x1, double y1, double x2, double y2) { return mag(x2-x1,y2-y1); }

	/**Calculates distance between 2 3D points
     * @param x1 point 1 x coordinate
     * @param y1 point 1 y coordinate
     * @param z1 point 1 z coordinate
     * @param x2 point 2 x coordinate
     * @param y2 point 2 y coordinate
     * @param z2 point 2 z coordinate
     * @return distance between points*/
	inline double dist (double x1, double y1, double z1, double x2, double y2, double z2) { return mag(x2-x1,y2-y1,z2-z1); }
	
	/**Linear interpolation
     * @param value1 value 1
     * @param value2 value 2
     * @param amt amount
     * @return interpolated result*/
	inline double lerp (double value1, double value2, double amt) { return value1*(1-amt)+value2*amt; }
	
	// Maps a ratio between an interval to another interval
	inline double map(double value,double low1, double high1, double low2, double high2) {
    	return (value-low1)/(high1-low1)*(high2-low2)+low2;
    }
	
	// Normalizes a number from another range into a value between 0 and 1.
	// Identical to map(value, low, high, 0, 1)
	inline double norm(double value,double low,double high) { return (value-low)/(high-low); }
	
	// Rounds a value to the closest int
	inline int round(double value) { return int(value+0.5); }
	
	
	
	// Square of a value
	inline double sq(double value) { return value*value; }
	
	// Converts from radians to degrees
	inline double degrees(double radians) { return radians / PI * 180; }
	
	// Converts from degrees to radians
	inline double radians(double degrees) { return degrees * PI / 180; }
	

     //call for sleepy delay functions
    #if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
        #include <windows.h>
         inline void delay( unsigned long ms ) { Sleep( ms ); }
    #else  /* presume POSIX */
        #include <unistd.h>
         inline void delay( unsigned long ms ) { usleep( ms * 1000 ); }
    #endif 	

    //============================================================================
	//
	// Drawing Attributes (file attributes.cpp)
	//


	/// Sets line color
	void stroke (const color& c);

	inline void stroke (double r, double g, double b, double a = MAXCOLOR) {
		stroke (color (r,g,b,a));
	}

	inline void stroke (double gray, double a = MAXCOLOR) {
		stroke (color (gray,a));
	}

	inline void noStroke() {
		stroke (color(0,0,0,0));
	}

	/// Sets fill color
	void fill (const color & color);

	inline void fill (double r, double g, double b, double a = MAXCOLOR) {
		fill (color (r,g,b,a));
	}

	inline void fill (double gray, double a = MAXCOLOR) {
		fill (color (gray,a));
	}

	inline void noFill() {
		fill (color(0,0,0,0));
	}

	/// Sets line / point width
	void strokeWeight (int weight);

	/// Draws background with given color
	void background (const color& c);

	void background(PImage * img);
	void background(PImage& img);

	inline void background (double r, double g, double b, double a = MAXCOLOR) {
		background (color (r,g,b,a));
	}

	inline void background (double gray, double a) {
		background (color (gray,a));
	}

	inline void background(int gray) {
		background(color(gray, MAXCOLOR));
	}

	// Line smoothing
	void smooth(); ///< Turns on smoothing

	void noSmooth(); ///< Turns off smoothing

	//========================================================================
	//
	// Drawing Primitives (file primitives.cpp)
	//

	/// Draws a 3D line segment given the coordinates
	/// of its endpoints.
	/// @param x0 The x coordinate of the first endpoint
	/// @param y0 The y coordinate of the first endpoint
	/// @param z0 The z coordinate of the first endpoint
	/// @param x1 The x coordinate of the second endpoint
	/// @param y1 The y coordinate of the second endpoint
	/// @param z1 The z coordinate of the second endpoint
	void line (double x0, double y0, double z0,
			   double x1, double y1, double z1);

	/// Draws a 2D line segment given the coordinates
	/// of its endpoints.
	/// @param x0 The x coordinate of the first endpoint
	/// @param y0 The y coordinate of the first endpoint
	/// @param x1 The x coordinate of the second endpoint
	/// @param y1 The y coordinate of the second endpoint
	inline void line (double x0, double y0, double x1, double y1) {
		line (x0, y0, 0, x1, y1, 0);
	}

	/// Draws a filled 3D triangle given the coordinates
	/// of its vertices.
	/// @param x0 The x coordinate of the first vertex
    	/// @param y0 The y coordinate of the first vertex
    	/// @param z0 The z coordinate of the first vertex
    	/// @param x1 The x coordinate of the second vertex
	/// @param y1 The y coordinate of the second vertex
    	/// @param z1 The z coordinate of the second vertex
	/// @param x2 The x coordinate of the third vertex
    	/// @param y2 The y coordinate of the third vertex
    	/// @param z2 The z coordinate of the third vertex
    	void triangle (double x0, double y0, double z0,
    		       double x1, double y1, double z1,
    			double x2, double y2, double z2) ;

	/// Draws a filled 2D triangle given the coordinates
	/// of its vertices.
	/// @param x0 The x coordinate of the first vertex
	/// @param y0 The y coordinate of the first vertex
	/// @param x1 The x coordinate of the second vertex
	/// @param y1 The y coordinate of the second vertex
	/// @param x2 The x coordinate of the third vertex
	/// @param y2 The y coordinate of the third vertex
        inline void triangle (double x0, double y0,
    		              double x1, double y1,
    			      double x2, double y2) {
    		triangle (x0, y0, 0, x1, y1, 0, x2, y2, 0);
    	}

    	/// Draws a filled 2D quadrilateral given the coordinates
	/// of its vertices.
	/// @param x0 The x coordinate of the first vertex
	/// @param y0 The y coordinate of the first vertex
	/// @param x1 The x coordinate of the second vertex
	/// @param y1 The y coordinate of the second vertex
	/// @param x2 The x coordinate of the third vertex
	/// @param y2 The y coordinate of the third vertex
	/// @param x3 The x coordinate of the third vertex
	/// @param y3 The y coordinate of the third vertex
     void quad (double x0, double y0,
    		    double x1, double y1,
   	            double x2, double y2,
   	            double x3, double y3);


    	/// Draws a point.
	/// @param x The x coordinate of the point
	/// @param y The y coordinate of the point
	/// @param z The z coordinate of the point
	void point (double x, double y, double z = 0);

	
	/// Configures the way the 'rect' function interprets its arguments
	/// @arg mode: either CENTER, RADIUS, CORNER or CORNERS
	void rectMode (unsigned mode);

	/// Draws an rectangle. The meaning of the arguments depend on the current
	/// rectMode. By default:
	/// @arg x, y: upper left corner of the rectangle
	/// @arg a, b: width and height of the rectangle
	void rect (double x, double y, double a, double b);

	/// Configures the number of line segments used for drawing an ellipse
	/// @arg n: number of sides
	void ellipseDetail (unsigned n);
	
	/// Configures the way the 'ellipse' function interprets its arguments
	/// @arg mode: either CENTER, RADIUS, CORNER or CORNERS
	void ellipseMode (unsigned mode);
	
	/// Draws an ellipse. The meaning of the arguments depend on the current
	/// ellipseMode. By default:
	/// @arg x, y: center of the ellipse
	/// @arg width, height: size of the ellipse axes
	void ellipse (double x, double y, double width, double height);
	
	
	/// Controls the detail used to render a sphere by adjusting the number 
	/// of vertices of the sphere mesh. The default resolution is 30, which creates 
	/// a fairly detailed sphere definition with vertices every 360/30 = 12 degrees.
	///
	/// @arg ures: number of segments used longitudinally per full circle revolution
	/// @arg vres: number of segments used latitudinally from top to bottom
	void sphereDetail (int ures, int vres);
	
	inline void sphereDetail (int res) { sphereDetail (res,res); }
	
	/// Draws a sphere centered at the origin with the given radius.
	/// @arg radius: radius of the sphere
	void sphere(double radius);
	
	/// Draws a parallelepiped centered at the origin
	/// @arg width: x size
	/// @arg height: y size
	/// @arg depth: z size
	void box(double width, double height, double depth);
	
	inline void box(double size) { box(size,size,size); }
    
	
	//========================================================================
	//
	// Shapes and vertices (file shapes.cpp)
	//

	// Starts the definition of a shape
	void beginShape(ShapeMode mode = POLYGON);

	// Finishes and renders the shape
	void endShape();

	// Adds a vertex to the shape
	void vertex (double x, double y, double z=0);

	// Specifies a normal for the next vertices
	void normal (double x, double y, double z);

    /// Establishes the Bézier level of detail, i.e., the number of points
    /// per Bézier curve segment.
	void bezierDetail(int n);

    /// Given the x or y coordinate of Bézier control points a,b,c,d and
    /// the value of the t parameter, return the corresponding
    /// coordinate of the point.
	double bezierPoint (double a, double b, double c, double d,double t);

	/// Given the x or y coordinate of Bézier control points a,b,c,d and
	/// the value of the t parameter, return the corresponding
	/// coordinate of the tangent at that point."""
	double bezierTangent (double a,double b,double c,double d,double t);

    /// Generates a cubic bezier arc. Arguments are of the form
    /// (cx1, cy1, cx2, cy2, x, y), i.e. coordinates
    /// for 3 control points in 2D. The first control point of the
    /// arc is the last point of the previous arc or the last vertex.
	void bezierVertex(double cx1,double cy1,double cz1,double cx2,double cy2,double cz2,double x,double y,double z);

	/// 2D version of bezierVertex
	inline void bezierVertex(double cx1,double cy1,double cx2,double cy2,double x,double y) {
		bezierVertex (cx1, cy1, 0, cx2, cy2, 0, x, y, 0);
	}

	/// Draws a cubic Bézier curve for the 4 control points
	void bezier(double x1,double y1,double z1,double cx1,double cy1,double cz1,
				double cx2,double cy2,double cz2,double x2,double y2,double z2);

	/// 2D version of bezier
	inline void bezier(double x1, double y1, double cx1, double cy1,
				double cx2, double cy2, double x2, double y2) {
		bezier (x1, y1, 0, cx1, cy1, 0, cx2, cy2, 0, x2, y2, 0);
	}

	//===========================================================================
	//
	// Transformations (file transformations.cpp)
	//

    /// Applies a translation transformation
    void translate (double dx, double dy, double dz);
    void translate(double dx, double dy);

    /// Applies a scale transformation
    void scale (double dx, double dy, double dz);
    void scale(double dx, double dy);
    /// Applies a uniform scale
    inline void scale (double factor) { scale (factor, factor, factor); }

    /// Applies a rotation transformation
    void rotate (double radians, double axisx, double axisy, double axisz);
    
	inline void rotateX (double radians) { rotate(radians, 1, 0, 0); }
	inline void rotateY (double radians) { rotate(radians, 0, 1, 0); }
	inline void rotateZ (double radians) { rotate(radians, 0, 0, 1); }
	inline void rotate (double radians) { rotateZ(radians); }

    /// Resets the transformation to none
    void resetMatrix();

    /// Fills matrix with the current transformation matrix
    void getMatrix (double matrix [16]);

    /// Multiplies given matrix by current transformation matrix
    void applyMatrix (double matrix [16]);

    /// Duplicates the top of the matrix stack
    void pushMatrix();

    /// Discards the top of the matrix stack
    void popMatrix();

    ///	Creates a viewing transformation given the camera position
	///	(eyex,eyey,eyez), the center of the scene (centerx, centery, centerz) and
	///	a vector to be used as the up direction (upx, upy, upz). If no args
	///	are passed, the standard camera is created.
	void camera (double eyeX, double eyeY, double eyeZ,
				 double centerX, double centerY, double centerZ,
				 double upX, double upY, double upZ);
	void camera ();

	/// Loads a perspective projection matrix, where
	/// fov is the field-of-view angle (in radians) for vertical direction, aspect
	/// is the ratio of width to height, znear is the z-position of nearest clipping
	/// plane and zfar is the z-position of nearest farthest plane. If no args are
	/// passed, the standard projection is created, i.e, equivalent to
	/// perspective(PI/3.0, width/height, cameraZ/10.0, cameraZ*10.0)
	/// where cameraZ is ((height/2.0) / tan(PI*60.0/360.0))
	void perspective(double fov, double aspect, double znear, double zfar);

	void perspective ();

	///	Loads an orthogonal projection matrix.
	///	The clipping volume in this case is an axes-aligned parallelepiped, where
	///	left and right are the minimum and maximum x values, top and bottom are
	///	the minimum and maximum y values, and near and far are the minimum and
	///	maximum z values. If no parameters are given, the default is used:
	///	ortho(0, width, 0, height, -height*2, height*2).
	void ortho(double left, double right, double bottom, double top, double near, double far);

	void ortho ();

    /// Returns the projected space coordinates of object coordinates ox,oy,oz
	void screenXYZ (double ox, double oy, double oz,
					double& sx, double& sy, double& sz);

	inline double screenX (double ox, double oy, double oz) {
		double tmpx, tmpy, tmpz;
		screenXYZ (ox, oy, oz, tmpx, tmpy, tmpz);
		return tmpx;
	}

	inline double screenY (double ox, double oy, double oz) {
		double tmpx, tmpy, tmpz;
		screenXYZ (ox, oy, oz, tmpx, tmpy, tmpz);
		return tmpy;
	}

	inline double screenZ (double ox, double oy, double oz) {
		double tmpx, tmpy, tmpz;
		screenXYZ (ox, oy, oz, tmpx, tmpy, tmpz);
		return tmpz;
	}


	//===========================================================================
	//
	// lights (file lights.cpp)
	//

    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg nx, ny, nz: direction vector.
    void directionalLight(float v1, float v2, float v3,
                          float nx, float ny, float nz);

    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void pointLight(float  v1,float  v2,float  v3,float  x,float  y,float  z);

    /// Defines a new ambient light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void ambientLight(float  v1,float  v2,float  v3, float  x=0, float  y=0, float  z=0);

    /// Defines a new spot light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    /// @arg nx, ny, nz: direction vector.
    /// @arg angle: angle in radians of spot aperture.
    /// @arg concentration: exponent which determines preference for spot axis.
    void spotLight(float v1, float  v2, float  v3,
                   float  x, float  y, float  z,
                   float  nx, float ny,float  nz,
                   float  angle, float  concentration);

    /// Defines a specular coefficients of new light sources.
    /// @arg v1, v2, v3: color components.
    void lightSpecular (float v1,float  v2,float  v3);

    /// Defines light attenuation factors
    /// @arg constant, linear, quadratic: coefficients of quadratic polynomial.
    void lightFalloff(float  constant,float  linear,float  quadratic);

    /// Turns on the default lighting
    void lights();

    // Turns off the lights
    void noLights();
    
    //text to console    
    template<class C>
	inline void print(const C& a) 			{ std::cout << a; }
	inline void print(const String * a) 	{ std::cout << (*a).self; }

	template<class C>
	inline void println(const C& a)			{ std::cout << a << std::endl; }
	inline void println(const String * a) 	{ std::cout << (*a).self << std::endl; }

	template<class C>
	inline void printerr(const C& a) 		{ std::cerr << a << std::endl; }
	inline void printerr(const String * a) 	{ std::cerr << (*a).self << std::endl; }


    //turns draw loop on or off
    inline void noLoop() { looping = false; }
    inline void loop() { looping = true; }

    //sets framerate
	inline void frameRate(int n) { framerate = n; }

    PImage createImage(int width, int height, int type);

    void image(PImage& img, int x, int y);
    void image(PImage& img, int x, int y, int w, int h);

    void image(PImage * img, int x, int y);
    void image(PImage * img, int x, int y, int w, int h);

    /**Configures the way the image function positions image
	 * @param mode either CENTER, CORNER or CORNERS*/
    void imageMode(unsigned mode);

    //time functions
    inline long millis() { return (long) ((long double) (clock()/(CLOCKS_PER_SEC/1000))); }
    int second();
    int minute();
    int hour();
    int day();
    int month();
    int year();



    //array functions
    /*
    template <class T>
    T * append(T & a, T b) {
    	int sz = sizeof(a)/sizeof(b);

    	T r = new T[sz+1];
    	for(int i=0; i<sz; i++) r[i] = a[i];
    	r[sz] = b;
    	return r;
    }

    
    template <class T>
    void arrayCopy(T src, int srcPosition, T dst, int dstPosition, int length);
    template <class T>
	void arrayCopy(T src, T dst, int length);
	
	template <class T>
	void arrayCopy(T & src, T & dst) {
		dst = *src;
	}
	
	*/

	//string functions
	/*
    Stringsz join(String str[], String separator) {
    	String r = "";
    	for(int i=0; i<str.length-1; i++) {
    		r += str[i];
    		r += separator;
    	}
    	r += str[str.length-1];

    	return r;
    }*/

    String trim(String str);

    /*
    String nf(int n) {

    }

    String nf(float n) {

    }*/


    inline void randomSeed(unsigned int randomSeed) {
      srand(randomSeed);
    }

    inline double random(double howbig) {
      return (double) (((double) (fmod(rand(),RAND_MAX))/RAND_MAX))*howbig;
    }

    inline float random(float howbig) {
      return (float) (((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*howbig;
    }

    inline float random(int howbig) {
      return (float) (((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*howbig;
    }

    inline double random(double howsmall, double howbig) {
      return (double) ((((double) (fmod(rand(),RAND_MAX))/RAND_MAX))*(howbig - howsmall))+howsmall;
    }

    inline float random(float howsmall, float howbig) {
      return (float) ((((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*(howbig - howsmall))+howsmall;
    }

    inline float random(int howsmall, int howbig) {
      return (float) ((((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*(howbig - howsmall))+howsmall;
    }



	/**Suppressed warnings for fread that size_t isn't used... well screw it we'll just trick it, from https://svn.boost.org/trac/boost/ticket/6118*/
	inline void ignore_size(size_t s){};
    
    const char * loadBytes(const char * src);

    void redraw();

    void pushStyle();
    void popStyle();

    ArrayList<String> loadStrings(String src);
    ArrayList<String> loadStrings(const char * src);
    

    //
	// Initialization (file cprocessing.cpp)
	//

    /// Sets up a window of the given size
    /// @param w Desired window width in pixels.
    /// @param h Desired window height in pixels.
    /// @param name Desired window title.

    void size (unsigned w, unsigned h, const char* name = "cprocessing");

    /// Run the drawing application
    void run();
}

#endif
