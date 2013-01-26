#include "cprocessing.hpp"

using namespace cprocessing;

namespace cprocessing {

  int second() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [3];
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (buffer,3,"%S",timeinfo);
    return atoi(buffer);
  }


  int minute() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [3];
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (buffer,3,"%M",timeinfo);
    return atoi(buffer);
  }


  int hour() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [3];
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (buffer,3,"%H",timeinfo);
    return atoi(buffer);
  }


  int day() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [3];
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (buffer,3,"%d",timeinfo);
    return atoi(buffer);
  }

  int month() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [3];
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (buffer,3,"%m",timeinfo);
    return atoi(buffer);
  }

  int year() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [5];
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (buffer,5,"%Y",timeinfo);
    return atoi(buffer);
  }

}