#include <vector>
#include <cassert>

#include "cprocessing.hpp"

typedef bool boolean;

#ifndef CPROCESSING_ARRAYLIST_
#define CPROCESSING_ARRAYLIST_

using namespace cprocessing;

namespace cprocessing {

    template <class T>
    class ArrayList {
    public:
        std::vector<T> self;
        int maxSize;    //currently ignored

        ArrayList() {}

        ArrayList(int size) { 
            maxSize = size;
        }

        ~ArrayList() {
            self.clear();
        }

        /**Adds element to ArrayList
         * @param e Element to add to end of ArrayList*/
        void add(T e) { 
            self.push_back(e);
        }

        /**Inserts element into ArrayList at specific position
         * @param e Element to add to end of ArrayList\
         * @param index position in ArrayList*/
        void add(T e, int index) { 
            self.insert(e, index);
        }

        /**Removes all elements from ArrayList*/
        void clear() {
            self.erase();
        }

        /**Copies ArrayList for your pleasure
         * @returns a copy of this ArrayList*/
        ArrayList clone() {
            return this;
        }

        boolean contains(T e) {
            for(int i=0; i<self.size(); i++) {
                if(&self[i] == &e) return true;
            }
            return false;
        }

        //void ensureCapacity(int n);

        T get(int index) {
            return self[index];
        }

        int indexOf(T e) {
            for(int i=0; i<self.size(); i++) {
                if(&self[i] == &e) return i;
            }
            return -1;
        }

        boolean isEmpty() {
            return ((self.size() == 0) ? true : false);
        }

        int lastIndexOf(T e) {
            for(int i=self.size(); i>0; i--) {
                if(&self[i] == &e) return i;
            }
            return -1;
        }

        void remove(int index) {
            self.erase(self.begin()+index);
        }

        //remove by element is removed from this as it coincides with int

        void removeRange(int start, int end) {
            self.erase(self.begin()+start, self.begin()+end);
        }

        void set(int index, T e) {
            self[index] = e;
        }

        int size() {
            return self.size();
        }

        T * toArray() {
            T r[self.size()];
            for(int i=0; i<self.size(); i++) {
                r[i] = self[i];
            }

            return r;
        }
        //void trimToSize();
    };
}

#endif