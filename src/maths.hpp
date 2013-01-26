#include "cprocessing.hpp"

#ifndef CPROCESSING_MATHS_
#define CPROCESSING_MATHS_

using namespace cprocessing;

namespace cprocessing {
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

}

#endif