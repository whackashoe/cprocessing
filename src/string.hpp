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

        bool operator== (const String& str);
        bool operator== (const std::string& str); 
        bool operator== (const char* s);          

        bool operator!= (const String& str);
        bool operator!= (const std::string& str); 
        bool operator!= (const char* s);          

        String operator+ (const String& str);
        String operator+ (const std::string& str);
        String operator+ (const char* s);
        String operator+ (const char c);

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


    /**Combines an array of Strings into one String, 
     * each separated by the character(s) used for the separator parameter. 
     * To join arrays of ints or floats, it's necessary to first convert them to Strings using nf() or nfs().
     * @param list ArrayList of Strings
     * @param separator String to be placed between each item
     * @returns String*/
    String join(ArrayList<String> list, String separator);

    /**This function is used to apply a regular expression to a piece of text, and return matching groups (elements found inside parentheses) as a String array. If there are no matches, a null value will be returned. If no groups are specified in the regular expression, but the sequence matches, an array of length 1 (with the matched text as the first element of the array) will be returned.
     * @param str the String to be searched
     * @param regexp the regexp to be used for matching
     * @returns String ArrayList of matches*/
    ArrayList<String> match(String str, String regexp);


    /**This function is used to apply a regular expression to a piece of text, and return a list of matching groups (elements found inside parentheses) as a two-dimensional String array. If there are no matches, a null value will be returned. If no groups are specified in the regular expression, but the sequence matches, a two dimensional array is still returned, but the second dimension is only of length one.
     * @param str the String to be searched
     * @param regexp the regexp to be used for matching
     * @returns String ArrayList of matches*/
    ArrayList<String> matchAll(String str, String regexp);

    //nf()  //TODO
    //nfc() //TODO
    //nfp() //TODO
    //nfs() //TODO

    /**The split() function breaks a String into pieces using a character or string as the delimiter. The delim parameter specifies the character or characters that mark the boundaries between each piece. A String ArrayList is returned that contains each of the pieces. 
     * @param value the String to be split
     * @param delim the character or String used to separate the data
     * @returns ArrayList<String>*/
    ArrayList<String> split(String value, String delim);
    
    //splitTokens()

    String trim(String str);
    String nf(int n, int d);
}

#endif
