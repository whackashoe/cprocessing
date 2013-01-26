#include "cprocessing.hpp"

#ifndef CPROCESSING_SHAPES_
#define CPROCESSING_SHAPES_

using namespace cprocessing;
namespace cprocessing {

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
}

#endif