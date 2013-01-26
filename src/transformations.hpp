#include "cprocessing.hpp"

#ifndef CPROCESSING_TRANSFORMATIONS_
#define CPROCESSING_TRANSFORMATIONS_

using namespace cprocessing;
namespace cprocessing {

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
}

#endif