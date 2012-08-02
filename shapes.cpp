/*
 * shapes.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: claudio
 */


#include <GL/glut.h>
#include <vector>
#include <cassert>
#include "cprocessing.hpp"

using namespace cprocessing;

///
/// Represents a polyline with several attributes such as normals and texture coordinates.
///
struct PPath {

	std::vector<PVector> vtx;  ///< An array of vertices
	std::vector<PVector> nrm;  ///< Normals for the vertices
	std::vector<PVector> tex;  ///< Texture coordinates for the vertices
	std::vector<color> fillC; ///< fill color of vertice
	std::vector<color> strokeC;///<stroke color for edge 

	PVector curNormal;     ///< Default normal
	PVector curTexCoord;   ///< Default Texture coordinates

	bool useNormal;     ///< Whether a normal was specified during the path construction
	bool useTexCoord;   ///< Whether a set of texture coordinates was specified during the path construction

	/// Constructor
	PPath () {
		curNormal = PVector(0,0,1);
		curTexCoord = PVector(0,0,0);
		useNormal = false;
		useTexCoord = false;
	}

	/// Adds a new point to the path
	void addVertex(const PVector& p) {
		vtx.push_back (p);
		nrm.push_back (curNormal);
		tex.push_back (curTexCoord);

		fillC.push_back(styles[styles.size()-1].fillColor);
		strokeC.push_back(styles[styles.size()-1].strokeColor);
	}

	/// Changes the current normal vector
	void setNormal(const PVector& n) { curNormal = n; useNormal = true; }

	/// Changes the current set of texture coordinates
	void setTexCoord (const PVector& t) { curTexCoord = t; useTexCoord = true; }

	/// Automatically computes normals from vertex positions. This is done computing
	/// triangle normals for groups of 3 vertices.
	/// @arg vstart: First vertex to compute.
	/// @arg vstride: How many vertices are skipped before computing the next normal
	/// @arg fan: Whether to use vtx[0] as first vertex of triangle rather than the
	///           first in the group.
	void setAutoNormals (int vstart, int vstride, bool fan = false) {
		int n = vtx.size(); // Number of normals / vertices
		assert (n == (int) nrm.size());
		int last = -1; // Last vertex which had its normal assigned
		for (int i = vstart; i < n; i+= vstride) {
			// Compute vectors for the last two triangle edges
			PVector v1 = vtx[i-1] - (fan ? vtx[0] : vtx[i-2]);
			PVector v2 = vtx[i] - vtx[i-1];
			// Normal given by the cross product
			PVector nv = v2.cross(v1);
			nv.normalize();
			// Set all vertices since the last to the new normal
			while (last < i) {
				last++;
				nrm [last] = nv;
			}
		}
	}
};

///
/// Some local module variables
///
static PPath shape; ///< Data for current shape
static ShapeMode mode; ///< Current shape type

//typedef stdvector<double> BlendFactor; ///< Blending factors for a cubic bézier
//static stdvector<BlendFactor> bezierBlend; ///< bezierDetail samples of Bézier blending functions

namespace cprocessing {

	/// Starts the definition of a shape
	void beginShape(ShapeMode mode) {
		PPath newshape;
		shape = newshape;
		mode = mode;
	}

	/// Finishes and renders the shape

	void endShape() {
		if(mode != NULL) glBegin(mode);
		else 			 glBegin(GL_POLYGON);

		for(uint i=0; i<shape.vtx.size(); i++) {
			if(shape.fillC[i].rgba[3] > 0) {
				glColor4ubv (shape.fillC[i].rgba);
				glVertex3d(shape.vtx[i].x, shape.vtx[i].y, shape.vtx[i].z);
			}
		}
		glEnd();

		glBegin(GL_LINE_STRIP);
		for(uint i=0; i<shape.vtx.size(); i++) {
			if(shape.strokeC[i].rgba[3] > 0) {
				glColor4ubv (shape.strokeC[i].rgba);
				glVertex3d(shape.vtx[i].x, shape.vtx[i].y, shape.vtx[i].z);
			}
		}
		if(shape.strokeC[shape.strokeC.size()-1].rgba[3] > 0) {
			glColor4ubv (shape.strokeC[shape.vtx.size()-1].rgba);
			glVertex3d(shape.vtx[0].x, shape.vtx[0].y, shape.vtx[0].z);
		}
		glEnd();
	}

	/// Adds a vertex to the shape
	void vertex (double x, double y, double z) {
		shape.addVertex (PVector(x,y,z));
	}

	/// Specifies a normal for the next vertices
	void normal (double x, double y, double z) {
		shape.setNormal (PVector (x,y,z));
	}

	///
	/// Functions to handle Bézier curves
	///

    /// Establishes the Bézier level of detail, i.e., the number of points
    /// per Bézier curve segment.
	void bezierDetail(int n)
	{
		// Remember the argument
		assert (n > 0);
	    styles[styles.size()-1].bezierDetail = n;
	    // Precompute blending factors
	    styles[styles.size()-1].bezierBlend.clear();
	    double t;
	    double u;
	    for (int i=0; i < n+1; i++) {
	    	t = double(i)/n;
	    	u = 1 - t;
	    	BlendFactor blend;
	    	blend.push_back (u*u*u);
	    	blend.push_back (3*u*u*t);
	    	blend.push_back (3*t*t*u);
	    	blend.push_back (t*t*t);
	    	styles[styles.size()-1].bezierBlend.push_back(blend);
	    }
	}

    /// Given the x or y coordinate of Bézier control points a,b,c,d and
    /// the value of the t parameter, return the corresponding
    /// coordinate of the point.
	double bezierPoint (double a, double b, double c, double d,double t)
	{
	    double u = 1.0 - t;
	    return a*u*u*u + b*3*u*u*t + c*3*t*t*u + d*t*t*t;
	}

	/// Given the x or y coordinate of Bézier control points a,b,c,d and
	/// the value of the t parameter, return the corresponding
	/// coordinate of the tangent at that point."""
	double bezierTangent (double a,double b,double c,double d,double t)
	{
	    double u = 1.0 - t;
	    return -a*3*u*u + b*(9*u*u-6*u) + c*(6*t-9*t*t) + d*3*t*t;
	}


	/// Generates a cubic bezier arc. Arguments are of the form
	/// (cx1, cy1, cz1, cx2, cy2, cz2, x, y, z), i.e. coordinates
	/// for 3 control points in 3D. The first control point of the
	/// arc is the last point of the previous arc or the last vertex.
	void bezierVertex(double cx1, double cy1, double cz1,
			          double cx2, double cy2, double cz2,
			          double x, double y, double z)
	{

		// Ignore if at least one vertex was not issued before
	    if (shape.vtx.size() == 0) return;

	    // Obtain the 4 control points
	    PVector a = shape.vtx[shape.vtx.size()-1];
	    PVector b = PVector (cx1, cy1, cz1);
	    PVector c = PVector (cx2, cy2, cz2);
	    PVector d = PVector (x, y, z);

	    // Put into shape a sampling of the curve
	    for (unsigned i = 0; i < styles[styles.size()-1].bezierBlend.size(); i++) {
	    	BlendFactor factor = styles[styles.size()-1].bezierBlend[i];
	    	PVector p = a*factor[0] + b*factor[1] + c*factor[2] + d*factor[3];
	    	shape.addVertex (p);
	    }
	}

	/// Draws a cubic Bézier curve for the 4 control points
	void bezier(double x1, double y1, double z1, double cx1, double cy1, double cz1,
				double cx2, double cy2, double cz2, double x2, double y2, double z2) {
		beginShape();
		vertex (x1, y1, z1);
		bezierVertex(cx1, cy1, cz1, cx2, cy2, cz2, x2, y2, z2);
		endShape();
	}
}
