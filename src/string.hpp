#include <string>
#include "cprocessing.hpp"

#ifndef CPROCESSING_STRING_
#define CPROCESSING_STRING_

typedef bool boolean;

using namespace cprocessing;

namespace cprocessing {

    class String {
    public:
        std::string self;
        
        String();
        String(const String& s);
        String(const char * s);
        String(std::string s);

        String& operator= (const String& str);
        String& operator= (const std::string& str);
        String& operator= (const char* s);
        String& operator= (const char c);
        
        String operator+ (const String& str)        const { String ss(this->self+str.self);  return ss; }
        String operator+ (const std::string& str)   const { String ss(this->self+str);       return ss; }
        String operator+ (const char* s)            const { String ss(this->self+s);         return ss; }
        String operator+ (const char c)             const { String ss(this->self+c);         return ss; }

        String& operator+= (const String str);
        String& operator+= (const std::string& str);
        String& operator+= (const char* s);
        String& operator+= (const char c);


        /**Grab the character at index
         * @param index between 0-length
         * @returns char at position*/
        char charAt(int index);

        /**Compare two Strings for equality
         * @param s String to compare to
         * @returns true if equal, false if not equal*/
        boolean equals(const String& s);

        /**Find position of first occurance of char
         * @param c character to find
         * @returns index of char or -1 if not found*/
        int indexOf(char c);

        /**Reports back length of String (number of characters)
         * @returns number of characters*/
        int length();

        /**Gives you a smaller fragment of string
         * @param beginIndex start here and copy rest of string
         * @returns String from beginIndex onwards*/
        String substring(int beginIndex);

        /**Gives you a smaller fragment of string
         * @param beginIndex start here and copy to endIndex
         * @param endIndex end copying here
         * @returns String from beginIndex to endIndex on this String*/
        String substring(int beginIndex, int endIndex);

        /**Converts String to lower case*/
        void toLowerCase();

        /**Converts String to upper case*/
        void toUpperCase();

        /**Converts String to char * 
         * @returns char array*/
        const char * toCharArray();
    };
}

#endif
