#include "cprocessing.hpp"

using namespace cprocessing;
namespace cprocessing {

  std::string loadBytes(std::string src) {
    std::ifstream in(src, std::ios::in | std::ios::binary);
    if (in)
    {
      std::string contents;
      in.seekg(0, std::ios::end);
      contents.resize(in.tellg());
      in.seekg(0, std::ios::beg);
      in.read(&contents[0], contents.size());
      in.close();
      return(contents);
    }
    throw(errno);
  }

  ArrayList<String> loadStrings(std::string src) {
    std::ifstream f(src);
    std::string line;
    ArrayList<String> strings;

    while(std::getline(f, line)) {
        strings.add(String(line));
    }

    return strings;
  }

  String currentPath() {
    char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
      printerr("An error occurred reading current directory:");
      printerr(errno);
      return NULL;
    }
    return String(cCurrentPath);
  }

  String fullPath() {
    String a = currentPath();
    String b = *args.get(0);

    return a+b;
  }

  void noLoop() { looping = false; }
  void loop()   { looping = true; }

  //makes drawing resume one step
  void redraw() { redrawflag = true; }

    //sets framerate
  void frameRate(int n) {
    framerate = n;
    framedelay = (1000.0f/(float)framerate);
  }

  //call for sleepy delay functions
  #if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
    #include <windows.h>
    void delay( unsigned long ms ) { Sleep( ms ); }
  #else  /* presume POSIX */
    #include <unistd.h>
    void delay( unsigned long ms ) { usleep( ms * 1000 ); }
  #endif

}