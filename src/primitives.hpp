
#include "cprocessing.hpp"

#ifndef CPROCESSING_PRIMITIVES_
#define CPROCESSING_PRIMITIVES_

using namespace cprocessing;

namespace cprocessing {

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


    void image(PImage& img, int x, int y);
    void image(PImage& img, int x, int y, int w, int h);

    void image(PImage * img, int x, int y);
    void image(PImage * img, int x, int y, int w, int h);

    /**Configures the way the image function positions image
	 * @param mode either CENTER, CORNER or CORNERS*/
    void imageMode(unsigned mode);

}

#endif