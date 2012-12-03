#include "cprocessing.hpp"

#ifndef CPROCESSING_HASHMAP_
#define CPROCESSING_HASHMAP_

template <class T>
class HashMap {
public:
    std::unordered_map<const char *, T> hm;
    HashMap() {}
    
    HashMap(int initialCapacity) {
        hm.reserve(initialCapacity);
    }
    HashMap(int initialCapacity, float loadFactor) {
        hm.reserve(initialCapacity);
        hm.max_load_factor();
    }
    HashMap(HashMap& map) {}


    //Returns a Set view of the keys contained in this map.
    ArrayList<const char *> keySet() {
        ArrayList<const char *> keys(ceil(hm.size/2));
        for(auto kv : hm) keys.add(kv.first);
        return keys;
    }

 	//Returns a Collection view of the values contained in this map.
 	ArrayList<T> values() {
        ArrayList<T> vals(floor(hm.size/2));
        for(auto kv : hm) vals.add(kv.second);
        return vals;
    }

    //Associates the specified value with the specified key in this map.
 	void put(const char * key, const T& value)      { hm[key] = value; }
    inline void put(String * key, const T& value)   { put(key->toCharArray(), value); }

 	//Returns the value to which the specified key is mapped, or null if this map contains no mapping for the key.
	T get(const char * key) 	        { return hm.at(key); }
	inline T get(String * key)          { return get(key->toCharArray()); }

    //Copies all of the mappings from the specified map to this map.
 	//void putAll(Map<? extends K,? extends V> m) 


 	//Returns the number of key-value mappings in this map.
 	inline int size()                   { return hm.size(); }

    //Returns true if this map contains no key-value mappings.
 	inline bool isEmpty()               { return hm.empty(); }

 	//Removes all of the mappings from this map.    
    inline void clear()                 { hm.clear(); }

    //Removes an element by its key
    bool remove(const char * s)         { return ((hm.erase(s) > 0) ? true : false); }
    inline bool remove(String * s)      { return remove(s->toCharArray()); }

    //Returns true if this map contains a mapping for the specified key.
 	bool containsKey(const char * s) 	{ return ((hm.count(s) > 0) ? true :false); }
 	inline bool containsKey(String * s) { return containsKey(s->toCharArray()); }

 	//Returns true if this map maps one or more keys to the specified value.
 	//bool containsValue(T) { return ((hm.count(T) > 0) ? true :false); }
};

#endif

