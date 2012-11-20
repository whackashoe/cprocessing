/*
 * transformations.cpp
 *
 *  Created on: Jul 19, 2011
 *      Author: claudio
 *
 *  Contains functions which deal with affine transformations
 */

#include <GL/glut.h>
#include <cmath>
#include "cprocessing.hpp"

#undef near
#undef far


namespace cprocessing {

	/**Applies a 3d translation transformation (moves the drawing pen for all following objects of frame)
	 * @param dx x amount of movement
	 * @param dy y amount of movement
	 * @param dz z amount of movement*/
	void translate (double dx, double dy, double dz) {
		glTranslatef (dx, dy, dz);
	}

	/**Applies a 2d translation transformation (moves the drawing pen for all following objects of frame)
	 * @param dx x amount of movement
	 * @param dy y amount of movement*/
    void translate (double dx, double dy) {
		glTranslatef (dx, dy, 0);
	}

	/**Applies a scale transformation in 3d (shrinks or grows all following objects of frame)
	  * @param dx x amount of "width"
	  * @param dy y amount of "height"
	  * @param dz z amount of "depth"*/
	void scale (double dx, double dy, double dz) {
		glScalef (dx, dy, dz);
	}

	/**Applies a scale transformation in 2d (shrinks or grows all following objects of frame)
	 * @param dx x amount of "width"
	 * @param dy y amount of "height"*/
	void scale (double dx, double dy) {
		glScalef (dx, dy, 1);
    }	
	
	/// Applies a rotation transformation
	void rotate (double radians, double axisx, double axisy, double axisz) {
		glRotatef (degrees(radians), axisx, axisy, axisz);
	}

	/* Resets the transformation to none */
	void resetMatrix() {
		glLoadIdentity();
	}

	/// Fills matrix with the current transformation matrix
	void getMatrix (double matrix [16]) {
		glGetDoublev (GL_MODELVIEW_MATRIX, matrix);
	}

	/// Multiplies current transformation matrix by given matrix
	void applyMatrix (double matrix [16]) {
		glMultMatrixd (matrix);
	}

	/// Duplicates the top of the matrix stack
	void pushMatrix() {
		glPushMatrix();
	}

	/// Discards the top of the matrix stack
	void popMatrix() {
		glPopMatrix ();
	}

	///	Creates a viewing transformation given the camera position
	///	(eyex,eyey,eyez), the center of the scene (centerx, centery, centerz) and
	///	a vector to be used as the up direction (upx, upy, upz). If no args
	///	are passed, the standard camera is created.
	void camera (double eyeX, double eyeY, double eyeZ,
			     double centerX, double centerY, double centerZ,
			     double upX, double upY, double upZ) {

		glLoadIdentity();

        if (HALF_PIXEL_SHIFT & config) {
            // Add a half-pixel shift in order to obtain sharper lines
            glTranslatef(0.5,0.5,0);
        }

        gluLookAt (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	}

	void camera () {
        camera (width/2.0, height/2.0, (height/2.0) / tan(M_PI*60.0 / 360.0),
                   width/2.0, height/2.0, 0, 0, 1, 0);
	}

	/// Loads a perspective projection matrix, where
	/// fov is the field-of-view angle (in radians) for vertical direction, aspect
	/// is the ratio of width to height, znear is the z-position of nearest clipping
	/// plane and zfar is the z-position of nearest farthest plane. If no args are
	/// passed, the standard projection is created, i.e, equivalent to
	/// perspective(PI/3.0, width/height, cameraZ/10.0, cameraZ*10.0)
	/// where cameraZ is ((height/2.0) / tan(PI*60.0/360.0))
	void perspective(double fov, double aspect, double znear, double zfar) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
        gluPerspective(fov * 180 / M_PI, aspect, znear, zfar);

        if (Y_DOWN & config) {
        	// invert the y axis if configuration asks for it
            glScalef(1,-1,1);
        }

        glMatrixMode(GL_MODELVIEW);
	}

    void perspective () {
		double cameraZ = height/2.0 / tan(M_PI*60/360);
        perspective(M_PI/3, width*1.0/height, cameraZ/100.0, cameraZ*10.0);
    }

	///	Loads an orthogonal projection matrix.
	///	The clipping volume in this case is an axes-aligned parallelepiped, where
	///	left and right are the minimum and maximum x values, top and bottom are
	///	the minimum and maximum y values, and near and far are the minimum and
	///	maximum z values. If no parameters are given, the default is used:
	///	ortho(0, width, 0, height, -height*2, height*2).
	void ortho(double left, double right, double bottom, double top, double near, double far) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if (Y_DOWN & config) {
			// invert the y axis if configuration asks for it
			double tmp = top;
			top = bottom;
			bottom = tmp;
		}

		glOrtho(left, right, bottom, top, near, far);
		
		glMatrixMode(GL_MODELVIEW);
	}

	void ortho () {
		ortho(0, width, 0, height, -height*2, height*2);
	}

    /// Returns the projected space coordinates of object coordinates ox,oy,oz
	void screenXYZ (double ox, double oy, double oz,
					double& sx, double& sy, double& sz) {
	    // variables for calling gluUnProject
	    int viewport[4];
	    double projmatrix [16], mviewmatrix [16];
	    // get current transformation state
	    glGetIntegerv(GL_VIEWPORT, viewport);
	    glGetDoublev(GL_MODELVIEW_MATRIX, mviewmatrix);
	    glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
	    // call gluProject
	    gluProject (ox,oy,oz,
	                mviewmatrix,projmatrix,viewport,
	                &sx, &sy, &sz);
	};
}
