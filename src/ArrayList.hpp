#include <vector>
#include <cassert>
#include "ALPiece.hpp"

#ifndef CPROCESSING_ARRAYLIST_
#define CPROCESSING_ARRAYLIST_

using namespace cprocessing;

namespace cprocessing {     
    
    class ArrayList {
    public:
        std::vector<__ALPiece> self;
        int maxSize;    //currently ignored

        ArrayList();
        ArrayList(int size);
	    ~ArrayList();
            
        template <class T>
        void add(T a) { self.push_back(__ALPiece(a)); }

        template <class T>            
        T & get(int n) { return &self[n]; }

        
        inline int size() { return self.size(); }
    };
}

#endif
