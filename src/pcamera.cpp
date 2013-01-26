#include "cprocessing.hpp"

using namespace cprocessing;

namespace cprocessing {         

    PCamera::PCamera() {
    	this->eyeX = width/2.0;
    	this->eyeY = height/2.0;
    	this->eyeZ = (height/2.0) / tan(PI*30.0 / 180.0);

    	this->centerX = width/2.0;
    	this->centerY = height/2.0;
    	this->centerZ = 0.0;

    	this->upX = 0.0;
    	this->upY = 1.0;
    	this->upZ = 0.0;
    }

    PCamera::PCamera(double centerX, double centerY, double centerZ) {
    	this->eyeX = width/2.0;
    	this->eyeY = height/2.0;
    	this->eyeZ = (height/2.0) / tan(PI*30.0 / 180.0);

    	this->centerX = centerX;
    	this->centerY = centerY;
    	this->centerZ = centerZ;

    	this->upX = 0.0;
    	this->upY = 1.0;
    	this->upZ = 0.0;
    }

    PCamera::PCamera( double eyeX, double eyeY, double eyeZ, 
    		          double centerX, double centerY, double centerZ) {
    	this->eyeX = eyeX;
    	this->eyeY = eyeY;
    	this->eyeZ = eyeZ;

    	this->centerX = centerX;
    	this->centerY = centerY;
    	this->centerZ = centerZ;

    	this->upX = 0.0;
    	this->upY = 1.0;
    	this->upZ = 0.0;
    }

    PCamera::PCamera(double eyeX, double eyeY, double eyeZ, 
            	     double centerX, double centerY, double centerZ, 
            		 double upX, double upY, double upZ) {
    	this->eyeX = eyeX;
    	this->eyeY = eyeY;
    	this->eyeZ = eyeZ;

    	this->centerX = centerX;
    	this->centerY = centerY;
    	this->centerZ = centerZ;

    	this->upX = eyeX;
    	this->upY = eyeY;
    	this->upZ = eyeZ;
    }


    void PCamera::moveX(double amnt) { eyeX += amnt; }
    void PCamera::moveY(double amnt) { eyeY += amnt; }
    void PCamera::moveZ(double amnt) { eyeZ += amnt; }

    void PCamera::lookX(double amnt) { centerX += amnt; }
    void PCamera::lookY(double amnt) { centerY += amnt; }
    void PCamera::lookZ(double amnt) { centerZ += amnt; }

    void PCamera::setEye(double x, double y, double z) { 
    	eyeX = x; 
    	eyeY = y; 
    	eyeZ = z;
    }

    void PCamera::setCenter(double x, double y, double z) { 
    	centerX = x; 
    	centerY = y; 
    	centerZ = z;
    }

    void PCamera::setUp(double x, double y, double z) {
    	upX = x; 
    	upY = y; 
    	upZ = z;
    }

    void PCamera::view() { 
    	camera(eyeX, eyeY, eyeZ, 
    		   centerX, centerY, centerZ, 
    		   upX, upY, upZ);
    }
}