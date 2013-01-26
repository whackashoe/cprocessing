#include "cprocessing.hpp"

using namespace cprocessing;
namespace cprocessing {

	String::String() {
		self = "";
	}

	String::String(const String& s) {
		(*this) = s;
	}

	String::String(std::string s) {
		self = s;
	}

	String::String(const char * s) {
		self = s;
	}

	String& String::operator= (const String& str) {
		this->self = str.self;
		return (*this);
	}

	String& String::operator= (const std::string& str) {
		this->self = str;
		return (*this);
	}

	String& String::operator= (const char* s) {
		this->self = s;
		return (*this);
	}

	String& String::operator= (const char c) {
		this->self = c;
		return (*this);
	}


	bool String::operator== (const String& str) {
		return ((this->self == str.self) ? true : false);
	}

	bool String::operator== (const std::string& str) {
		return ((this->self == str) ? true : false);
	}

	bool String::operator== (const char* s) { 
		return ((this->self == s) ? true : false);
	}

	bool String::operator!= (const String& str) { 
		return ((this->self != str.self) ? true : false);
	}

	bool String::operator!= (const std::string& str) { 
		return ((this->self != str) ? true : false);
	}

	bool String::operator!= (const char* s) { 
		return ((this->self != s) ? true : false);

	}

	String String::operator+ (const String& str) { 
		String ss(this->self+str.self);
		return ss;
	}

	String String::operator+ (const std::string& str) { 
		String ss(this->self+str);
		return ss;
	}

	String String::operator+ (const char* s) {
		String ss(this->self+s);
		return ss;
	}

	String String::operator+ (const char c) {
		String ss(this->self+c);
		return ss;
	}

	String& String::operator+= (const String str) {
		this->self += str.self;
		return (*this);
	}

	String& String::operator+= (const std::string& str) {
		this->self += str;
		return (*this);
	}

	String& String::operator+= (const char* s) {
		this->self += s;
		return (*this);
	}

	String& String::operator+= (const char c) {
		this->self += c;
		return (*this);
	}

	char String::charAt(int index) {
		return self[index];
	}

	boolean String::equals(const String& s) {
		if(self.compare(s.self) == 0) return true;
		return false;
	}

	int String::indexOf(char c) {
		for(unsigned int i=0; i<self.size(); i++) {
			if(self[i] == c) return i;
		}
		return -1;
	}

	int String::length() {
		return self.size();
	}


	String String::substring(int beginIndex) {
		return String(self.substr(beginIndex, self.size()-beginIndex));
	}

	String String::substring(int beginIndex, int endIndex) {
		return String(self.substr(beginIndex, beginIndex+endIndex));
	}

	void String::toLowerCase() {
	    std::transform(self.begin(), self.end(), self.begin(), ::tolower);
	}

	void String::toUpperCase() {
		std::transform(self.begin(), self.end(), self.begin(), ::toupper);
	}

	const char * String::toCharArray() {
		return self.c_str();
	}




	String nf(int n, int d) {
      char * buf = new char[d];
      sprintf(buf,"%d",n);
      String t(buf);
      String b = "";

      if(t.length() > d) {
        //FIXME: cut off end e.g. make 124567 with d=4 1245
      }

      for(int i=t.length(); i < d; i++) {
        b += "0";
      }

      String r = b + t;
      return r;
    }
}