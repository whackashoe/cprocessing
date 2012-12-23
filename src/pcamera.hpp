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

        PCamera();
        PCamera(double centerX, double centerY, double centerZ);

        PCamera(double eyeX, double eyeY, double eyeZ, 
        		double centerX, double centerY, double centerZ);

        PCamera(double eyeX, double eyeY, double eyeZ, 
        		double centerX, double centerY, double centerZ, 
        		double upX, double upY, double upZ);


	    inline void moveX(double amnt);
	    inline void moveY(double amnt);
	    inline void moveZ(double amnt);

	    inline void lookX(double amnt);
	    inline void lookY(double amnt);
	    inline void lookZ(double amnt);

	    inline void setEye(double x, double y, double z);
	    inline void setCenter(double x, double y, double z);

	    inline void setUp(double x, double y, double z);
	    inline void view();
	};
}

#endif
