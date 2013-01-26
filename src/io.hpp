#include "cprocessing.hpp"

#ifndef CPROCESSING_IO_
#define CPROCESSING_IO_

using namespace cprocessing;
namespace cprocessing {

    std::string loadBytes(std::string src);
    ArrayList<String> loadStrings(std::string src);

    String currentPath();
    String fullPath();

    //text to console    
    template<class C>
	inline void print(const C& a) 			 { std::cout << a; }
	inline void print(const String a)   	 { std::cout << a.self; }

	template<class C>
	inline void println(const C& a)				{ std::cout << a << std::endl; }
	inline void println(const String a) 		{ std::cout << a.self << std::endl; }

	template<class C>
	inline void printerr(const C& a) 			{ std::cerr << a << std::endl; }
	inline void printerr(const String a) 		{ std::cerr << a.self << std::endl; }

	//turns draw loop on or off
    void noLoop();
    void loop();

    //makes drawing resume one step
    void redraw();

    //sets framerate
	void frameRate(int n);

	 //call for sleepy delay functions
    #if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
        #include <windows.h>
         inline void delay(unsigned long ms);
    #else  /* presume POSIX */
        #include <unistd.h>
         inline void delay(unsigned long ms);
    #endif

}

#endif