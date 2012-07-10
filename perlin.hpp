// perlinNoise.h
// Class to implement coherent noise over 1, 2, or 3 dimensions.
// Implementation based on the Perlin noise function. Thanks to 
// Ken Perlin of NYU for publishing his algorithm online.
/////////////////////////////////////////////////////////////////////
// Copyright (c) 2001, Matt Zucker
// You may use this source code as you wish, but it is provided
// with no warranty. Please email me at mazucker@vassar.edu if 
// you find it useful.
/////////////////////////////////////////////////////////////////////

#ifndef _NOISE_CLASS_H_
#define _NOISE_CLASS_H_

#include <stdlib.h>


// It must be true that (x % NOISE_WRAP_INDEX) == (x & NOISE_MOD_MASK)
// so NOISE_WRAP_INDEX must be a power of two, and NOISE_MOD_MASK must be
// that power of 2 - 1.  as indices are implemented, as unsigned chars,
// NOISE_WRAP_INDEX shoud be less than or equal to 256.
// There's no good reason to change it from 256, really.

#define NOISE_WRAP_INDEX  256
#define NOISE_MOD_MASK    255

// A large power of 2, we'll go for 4096, to add to negative numbers
// in order to make them positive

#define NOISE_LARGE_PWR2  4096

namespace cprocessing {
  class perlinNoise {
    private:
      static unsigned initialized;
    
      static unsigned permutationTable[NOISE_WRAP_INDEX*2 + 2]; // permutation table
      static double    gradientTable1d[NOISE_WRAP_INDEX*2 + 2];  // 1d gradient lookup table.
      static double    gradientTable2d[NOISE_WRAP_INDEX*2 + 2][2]; // 2d gradient lookup table.
      static double    gradientTable3d[NOISE_WRAP_INDEX*2 + 2][3]; // 3d gradient lookup table.
      
      static double    randNoisedouble();     // generate a random double in [-1,1]
      static void     normalize2d(double vector[2]); // normalize a 2d vector
      static void     normalize3d(double vector[3]); // normalize a 3d vector
      static void     generateLookupTables();   // fill in table entries
      
    public:
      static void     reseed();     // reseed random generator & regenerate tables
      static void     reseed(unsigned int rSeed); // same, but with specified seed

      static double    noise1d(double pos[1]);  // 1D call using an array for passing pos
      static double    noise2d(double pos[2]);  // 2D call using an array for passing pos
      static double    noise3d(double pos[3]);  // 3D call using an array for passing pos

      static double    noise(double);   // use individual elements for passing pos
      static double    noise(double, double);
      static double    noise(double, double, double);
  };

  //void noiseDetail(int octaves);
  //void noiseDetail(int octaves, double falloff);
  void noiseSeed(int n);
  double noise(double x);
  double noise(double x, double y);
  double noise(double x, double y, double z);
}


#endif