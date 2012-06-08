#include <vector>
#include <cassert>

#ifndef CPROCESSING_ARRAYLIST_
#define CPROCESSING_ARRAYLIST_


using namespace cprocessing;

namespace cprocessing {     
    
    class ArrayList {
    public:
        template <class C>
        std::vector<const C&> self;

        ArrayList();
	    ~ArrayList();
            
        template <class C>
        void add(const C& a) { self.push_back(a); }

        template <class C>            
        C& get(int n) { return self[n]; }

        
        inline int size() { return self.size(); }
    };
}

#endif