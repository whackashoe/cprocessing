#include "cprocessing.hpp"

#ifndef CPROCESSING_RANDOM_
#define CPROCESSING_RANDOM_

using namespace cprocessing;
namespace cprocessing {

  inline void randomSeed(unsigned int randomSeed) {
    srand(randomSeed);
  }

  inline double random(double howbig) {
    return (double) (((double) (fmod(rand(),RAND_MAX))/RAND_MAX))*howbig;
  }

  inline float random(float howbig) {
    return (float) (((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*howbig;
  }

  inline float random(int howbig) {
    return (float) (((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*howbig;
  }

  inline double random(double howsmall, double howbig) {
    return (double) ((((double) (fmod(rand(),RAND_MAX))/RAND_MAX))*(howbig - howsmall))+howsmall;
  }

  inline float random(float howsmall, float howbig) {
    return (float) ((((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*(howbig - howsmall))+howsmall;
  }

  inline float random(int howsmall, int howbig) {
    return (float) ((((float) (fmod(rand(),RAND_MAX))/RAND_MAX))*(howbig - howsmall))+howsmall;
  }
}

#endif