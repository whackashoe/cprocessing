#include "cprocessing.hpp"


#ifndef CPROCESSING_PCAMERA_
#define CPROCESSING_PCAMERA_


using namespace cprocessing;

namespace cprocessing {         
    /// Encapsulates a 2D RGBA image
	class PCamera {
	public:
		double eyeX, eyeY, eyeZ;
		double centerX, centerY, centerZ;
		double upX, upY, upZ;

		/**Sets the camera to the default position, pointing to the center of the display window with the Y axis as up*/
        PCamera();

        /**Sets the camera eye to the default position, 
         * pointing to the values given for center position, 
         * with the Y axis as up
         * @param centerX the center of where you want the camera to point; along the x axis
         * @param centerY the center of where you want the camera to point; along the y axis
         * @param centerZ the center of where you want the camera to point; along the z axis*/
        PCamera(double centerX, double centerY, double centerZ);

        /**Sets the camera eye to the values given, 
         * pointing to the values given for center position, 
         * with the Y axis as up
         * @param eyeX the position of the eye of the camera along the x axis
         * @param eyeY the position of the eye of the camera along the y axis
         * @param eyeZ the position of the eye of the camera along the z axis
         * @param centerX the center of where you want the camera to point; along the x axis
         * @param centerY the center of where you want the camera to point; along the y axis
         * @param centerZ the center of where you want the camera to point; along the z axis*/
        PCamera(double eyeX, double eyeY, double eyeZ, 
        		double centerX, double centerY, double centerZ);

        /**Sets the camera eye to the values given, 
         * pointing to the values given for center position, 
         * with orientation of the camera given as well (IE all values set)
         * @param eyeX the position of the eye of the camera along the x axis
         * @param eyeY the position of the eye of the camera along the y axis
         * @param eyeZ the position of the eye of the camera along the z axis
         * @param centerX the center of where you want the camera to point; along the x axis
         * @param centerY the center of where you want the camera to point; along the y axis
         * @param centerZ the center of where you want the camera to point; along the z axis
         * @param upX the setting for up or down (usually -1.0, 0.0, or 1.0)
         * @param upY the setting for up or down (usually -1.0, 0.0, or 1.0)
         * @param upZ the setting for up or down (usually -1.0, 0.0, or 1.0)
         */
        PCamera(double eyeX, double eyeY, double eyeZ, 
        		double centerX, double centerY, double centerZ, 
        		double upX, double upY, double upZ);

        /**Moves the position of the camera eye along the x axis some amount
		 * @param amnt any positive or negative number*/
	    void moveX(double amnt);
	    /**Moves the position of the camera eye along the y axis some amount
		 * @param amnt any positive or negative number*/
	    void moveY(double amnt);
	    /**Moves the position of the camera eye along the z axis some amount
		 * @param amnt any positive or negative number*/
	    void moveZ(double amnt);

	    /**Changes where the position of the camera is looking some amount along the x axis
		 * @param amnt any positive or negative number*/
	    void lookX(double amnt);

	    /**Changes where the position of the camera is looking some amount along the y axis
		 * @param amnt any positive or negative number*/
	    void lookY(double amnt);

	    /**Changes where the position of the camera is looking some amount along the z axis
		 * @param amnt any positive or negative number*/
	    void lookZ(double amnt);

	    /**Changes where the position of the camera eye is to a set position
		 * @param x any number - for the x axis
		 * @param y any number - for the y axis
		 * @param z any number - for the z axis*/
	    void setEye(double x, double y, double z=0.0);

	    /**Changes where the position of the camera is looking to a set position
		 * @param x any number - for the x axis
		 * @param y any number - for the y axis
		 * @param z any number - for the z axis*/
	    void setCenter(double x, double y, double z=0.0);

	    /**Changes the orientation of the camera (which side is "up")
		 * @param x any number - for the x axis (usually -1.0, 0.0, or 1.0)
		 * @param y any number - for the y axis (usually -1.0, 0.0, or 1.0)
		 * @param z any number - for the z axis (usually -1.0, 0.0, or 1.0)*/
	    void setUp(double x, double y, double z=0.0);

	    /**Makes the camera view what it is looking at, which in turn updates your screen
	     * This internally is a call to camera(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);*/
	    void view();
	};
}

#endif
