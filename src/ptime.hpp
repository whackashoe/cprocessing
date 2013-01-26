#include "cprocessing.hpp"


#ifndef CPROCESSING_PTIME_
#define CPROCESSING_PTIME_

using namespace cprocessing;
namespace cprocessing {
	inline long millis() { return (long) ((long double) (clock()/(CLOCKS_PER_SEC/1000))); }
	int second();
	int minute();
	int hour();
	int day();
	int month();
	int year();
}

#endif