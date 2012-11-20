#include <cassert>

#ifndef CPROCESSING_HASHMAP_
#define CPROCESSING_HASHMAP_

template <typename T>
class HashMap {
public:
    hash_map<T, int> int_hashmap;
    HashMap();
    HashMap(initialCapacity);
    HashMap(initialCapacity, loadFactor);
    HashMap(map);


};

#endif

