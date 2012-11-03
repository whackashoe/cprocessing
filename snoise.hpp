#ifndef SIMPLEXNOISE_HPP_
#define SIMPLEXNOISE_HPP_

namespace cprocessing {
        class SimplexNoise {
        private:
                static double SQRT3;
                static double SQRT5;

                /**
                 * Skewing and unskewing factors for 2D, 3D and 4D, some of them
                 * pre-multiplied.
                 */
                static double F2;
                static double G2;
                static double G22;

                static double F3;
                static double G3;

                static double F4;
                static double G4;
                static double G42;
                static double G43;
                static double G44;

                /**
                 * Gradient vectors (pointing to mid points of all edges of a unit
                 * cube)
                 */
                static int grad3[][3];
                static int grad4[][4];

                /**
                 * Permutation table
                 */
                static int p[];
                /**
                 * To remove the need for index wrapping, double the permutation table
                 * length
                 */
                static int perm[512];
                static int permMod12[512];
                /**
                 * A lookup table to traverse the simplex around a given point in 4D.
                 * Details can be found where this table is used, in the 4D noise method.
                 */
                static int simplex[][4];

                inline double dot(int g[], double x, double y);
		inline double dot(int g[], double x, double y, double z);
		inline double dot(int g[], double x, double y, double z, double w);
		inline int fastfloor(double x);
        public:
                SimplexNoise();
        	double noise(double x, double y);
        	double noise(double x, double y, double z);
        	double noise(double x, double y, double z, double w);
        };


        //simplex noise functions
        double snoise(double x);
        double snoise(double x, double y);
        double snoise(double x, double y, double z);
        double snoise(double x, double y, double z, double w);
}
#endif