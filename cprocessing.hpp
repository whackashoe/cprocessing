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
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//guard, if these are defined they will break windows compilation
#ifndef RADIUS
#undef RADIUS
#endif
#ifndef DELETE
#undef DELETE
#endif

//rewrite basic syntax
#ifndef exit();
#define exit(); exit(EXIT_SUCCESS);
#endif

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
		   RADIUS, CORNER, CORNERS, RGB, HSB, ARGB, ALPHA
	};

	/// Configuration flags
	enum {
		HALF_PIXEL_SHIFT = 1,    // Whether to shift vertex coordinates by half a pixel (true by default).
		Y_DOWN           = 1<<1, // Whether to flip the y axis so it points down, rather than up (true by default).
		BACK_BUFFER		 = 1<<2  // Whether to use a backup buffer which is copied every frame in order to effect a stable drawing
		                         // canvas which is maintained between frames (true by default, but should be disabled for speed).
	};

	/// Shape constants
	typedef enum {
		POINTS, LINES, LINE_LOOP, LINE_STRIP, TRIANGLES,  TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP, POLYGON
	} ShapeMode;

	/// Parameter for the endShape function
	typedef enum {
		OPEN = 0, CLOSE = 1
	} ShapeClose;

    #define MAXCOLOR 1e10
    
	/// Color class
	struct color {
		unsigned char rgba[4];
		/// Empty constructor
		color () {}
		/// Constructor
		color (double r, double g, double b, double a = MAXCOLOR);
		/// Constructor for gray values
		color (double gray, double alpha = MAXCOLOR);
		/// Fills a float array with color values scaled for the interval 0..1
		void toFloat(float a[]);
		/// Fills a double array with color values scaled for the interval 0..1
		void toDouble(double a[]);
	};
	
	/// Encapsulates a 2D RGBA image
	class PImage {
	public:
	    color * pixels;  ///< Where the pixels are actually stored. Stored row by row
	                     /// from top (row 0) to bottom
	    int width;       ///< width of the image (size of row)
	    int height;      ///< height of the image (number of rows)
	    
	    /// Constructor
	    /// @arg width horizontal size
	    /// @arg height vertical size
	    /// @arg type ARGB, RGB or ALPHA
	    PImage (int width, int height, int type = ARGB);
	    
	    /// Destructor
	    ~PImage ();
	    
	    /// Returns a copy of this image
	    PImage get(); 
	    
	    /// Returns a copy of a subrectangle of this image
	    PImage get (int x, int y, int w, int h);
    
	    /// Returns the pixel at coordinate (x,y) 
	    inline color get(int x, int y) {
	        assert(x >=0 && x < width && y >= 0 && y < height && pixels!=0);
	        return pixels[y*width+x];
	    }	    
	    
	    /// Draws the image at position (x, y) of the screen
	    void put (int x, int y);
	    
	    /// Draws the image at position (x, y) of the screen with the given width and height
	    void put (int x, int y, int w, int h);	    
	};
	

	/// Represents a vector (or, sometimes, a point) in 3D
	class PVector {
	public:
		double x, y, z; ///< The coordinates
		/// Constructor
		PVector (double thex = 0, double they = 0, double thez = 0) : x(thex), y(they), z(thez) {}

		/// Assignment from coordinates
		void set (double thex = 0, double they = 0, double thez = 0) { x=thex; y=they; z=thez; }

		/// Assignment from another PVector
		void set (const PVector& other) { *this = other; }

		/// Assignment from an array of doubles
		void set (const double other[]) { x = other[0]; y = other[1]; z = other[2]; }

		/// Copy of the vector
		PVector get() { return *this; }

		/// Add
		PVector operator+(const PVector& other) const { return PVector(x+other.x, y+other.y, z+other.z); }
		PVector add (const PVector& other) const { return *this+other; }
		static PVector add (const PVector& a, const PVector& b) { return a+b; }

		/// Subtract
		PVector operator-(const PVector& other) const { return PVector(x-other.x, y-other.y, z-other.z); }
		PVector sub (const PVector& other) const { return *this-other; }
		static PVector sub (const PVector& a, const PVector& b) { return a-b; }

		/// Multiply by scalar
		PVector operator*(double s) const { return PVector(s*x, s*y, s*z); }
		PVector mult(double s) const { return *this*s; }
		static PVector mult(const PVector& v, double s)  { return v*s; }

		/// Divide by scalar
		PVector operator/(double s) const { return *this * (1/s); }
		PVector div(double s) const { return *this/s; }
		static PVector div(const PVector& v, double s)  { return v/s; }

		/// Dot product
		double dot (const PVector& other) const { return x*other.x + y*other.y + z*other.z; }
		static double dot (const PVector& a, const PVector& b) { return a.dot(b); }

		/// Cross product
		static PVector cross (const PVector& v1, const PVector& v2) {
			return PVector(v1.y * v2.z - v2.y * v1.z,
						v1.z * v2.x - v2.z * v1.x,
						v1.x * v2.y - v2.x * v1.y);
		}
		PVector cross (const PVector& other) const { return PVector::cross(*this,other); }

		/// Magnitude
		double mag () const { return sqrt(this->dot(*this)); }

		/// Distance between two points
		double dist (const PVector& other) const { return (this->sub(other)).mag(); }
		static double dist (const PVector& a, const PVector& b) { return a.dist(b); }

		/// Normalize (make unit length)
		void normalize() {
			double len = mag();
			if (len>1e-10)
			*this = *this / len;
		}

		/// Angle between two vectors
		static double angleBetween (const PVector& a, const PVector& b) {
			PVector acopy = a; acopy.normalize();
			PVector bcopy = b; bcopy.normalize();
			return acos(acopy.dot(bcopy));
		}

		/// Limit the magnitude of this vector to the value used for the max parameter
		void limit (double max) {
			double sz = this->mag();
			if (sz>max) *this = *this * (max / sz);
		}

		/// Returns vector coordinates as an array
		double* array() { return (double*) this; /* I KNOW this is unsafe! */ }
	};


	//============================================================================
	//
	// Global variables (defined in file cprocessing.cpp)
	//
	extern int mouseX;  ///< Mouse x coordinate
	extern int mouseY;  ///< Mouse y coordinate
	extern int pmouseX; ///< Previous mouse x coordinate
	extern int pmouseY; ///< Previous mouse y coordinate
	extern bool mousePressed; ///< Whether any mouse button is pressed
	extern int mouseButton; ///< Which button is pressed
	extern bool keyPressed; ///< Whether a key was pressed
	extern unsigned char key; ///< Which (ASCII) key was pressed
	extern int keyCode; ///< Code for the last pressed key
	extern int width; ///< window width
	extern int height; ///< window height
	extern unsigned config; ///< configuration flags
	extern int frameRate; ///< Frames per second
	extern color strokeColor;  ///< Line drawing color
	extern color fillColor;   ///< Area drawing color


	//===========================================================================
	//
	// Some math utility functions and constants
	//
	const double PI = 3.14159265358979323846;
	const double TWO_PI = 2*PI;
	const double HALF_PI = PI/2;
	const double QUARTER_PI = PI/4;
	
	/// Minimum between two numbers
	///
	template<class C>
	inline C min(const C& a, const C& b) { return a<b ? a : b; }
	
	/// Maximum between two numbers
	///
	template<class C>
	inline C max(const C& a, const C& b) { return a>b ? a : b; }
	
	/// Minimum between three numbers
	///
	template<class C>
	inline C min(const C& a, const C& b, const C& c) { return a<b ? min(a,c) : min(b,c); }
	
	/// Maximum between three numbers
	///
	template<class C>
	inline C max(const C& a, const C& b, const C& c) { return a>b ? max(a,c) : max(b,c); }
	
	// Constrain value to a certain range
	template<class C>
	inline C constrain(const C& a, const C& minv, const C& maxv) { return min(maxv,max(minv,a)); }
	
	// Magnitude of a 2D vector
	inline double mag (double a, double b) { return sqrt(a*a+b*b); }
	
	// Magnitude of a 3D vector
	inline double mag (double a, double b, double c) { return sqrt(a*a+b*b+c*c); }
	
	// Distance between 2 2D points
	inline double dist (double x1, double y1, double x2, double y2) { return mag(x2-x1,y2-y1); }

	// Distance between 2 3D points
	inline double dist (double x1, double y1, double z1, double x2, double y2, double z2) { return mag(x2-x1,y2-y1,z2-z1); }
	
	// Linear interpolation
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
	

	//============================================================================
	//
	// Drawing Attributes (file attributes.cpp)
	//


	/// Changes the way Processing interprets color data.
	/// The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems.
	void colorMode(unsigned mode, double range1, double range2, double range3, double range4);

	void colorMode(unsigned mode);

	inline void colorMode(unsigned mode, double range){
		colorMode(mode, range, range, range, range);
	}

	inline void colorMode(unsigned mode, double range1, double range2, double range3){
		colorMode(mode, range1, range2, range3, MAXCOLOR);
	}

	/// Extracts the alpha value from a color, scaled to match current colorMode()
	double alpha(const color & color);
	
	/// Extracts the red value from a color, scaled to match current colorMode()
	double red(const color & color);
	
	/// Extracts the green value from a color, scaled to match current colorMode()
	double green(const color & color);
	
	/// Extracts the blue value from a color, scaled to match current colorMode()
	double blue(const color & color);
	
	/// Extracts the hue value from a color, scaled to match current colorMode()
	double hue(const color & color);
	
	/// Extracts the saturation value from a color, scaled to match current colorMode()
	double saturation(const color & color);
	
	/// Extracts the brightness value from a color, scaled to match current colorMode()
	double brightness(const color & color);
	
	
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
	void background (const color&);

	inline void background (double r, double g, double b, double a = MAXCOLOR) {
		background (color (r,g,b,a));
	}

	inline void background (double gray, double a = MAXCOLOR) {
		background (color (gray,a));
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
	void endShape(ShapeClose close = OPEN);

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

    /// Applies a scale transformation
    void scale (double dx, double dy, double dz);

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
    void directionalLight(double v1, double v2, double v3,
                          double nx, double ny, double nz);

    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void pointLight(double  v1,double  v2,double  v3,double  x,double  y,double  z);

    /// Defines a new ambient light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void ambientLight(double  v1,double  v2,double  v3, double  x=0, double  y=0, double  z=0);

    /// Defines a new spot light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    /// @arg nx, ny, nz: direction vector.
    /// @arg angle: angle in radians of spot aperture.
    /// @arg concentration: exponent which determines preference for spot axis.
    void spotLight(double v1, double  v2, double  v3,
                   double  x, double  y, double  z,
                   double  nx, double ny,double  nz,
                   double  angle, double  concentration);

    /// Defines a specular coefficients of new light sources.
    /// @arg v1, v2, v3: color components.
    void lightSpecular (double v1,double  v2,double  v3);

    /// Defines light attenuation factors
    /// @args constant, linear, quadratic: coefficients of quadratic polynomial.
    void lightFalloff(double  constant,double  linear,double  quadratic);

    /// Turns on the default lighting
    void lights();

    // Turns off the lights
    void noLights();
    
    //text to console
    void print(std::string s);
    void println(std::string s);

    //
	// Initialization (file cprocessing.cpp)
	//

    /// Sets up a window of the given size
    /// @param width Desired window width in pixels.
    /// @param height Desired window height in pixels.
    /// @param name Desired window title.
    void size (unsigned width, unsigned height, const char* name = "Graphics");

    /// Run the drawing application
    void run();
}

#endif /* CPROCESSING_HPP_ */
