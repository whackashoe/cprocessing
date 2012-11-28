#include <vector>
#include <cassert>

#include "cprocessing.hpp"

typedef bool boolean;

#ifndef CPROCESSING_ARRAYLIST_
#define CPROCESSING_ARRAYLIST_

using namespace cprocessing;

namespace cprocessing {

    template <typename T>
    class ArrayList {
    public:
        std::vector<T> self;
        int maxSize;    //currently ignored

        ArrayList() {}

        ArrayList(int size) { 
            self.reserve(size);
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
            self.clear();
        }

        /**Copies ArrayList for your pleasure
         * @returns a copy of this ArrayList*/
        ArrayList clone() {
            return this;
        }

        /**Checks ArrayList if it contains an element (slow)
         * @param e Element to check if it is inside
         * @returns true if contains, false if not*/
        boolean contains(T e) {
            for(int i=0; i<self.size(); i++) {
                if(&self[i] == &e) return true;
            }
            return false;
        }

        //void ensureCapacity(int n);

        /**Grabs element from ArrayList for you to use
         * @param index position in ArrayList to grab from (0 - size())
         * @returns element at that index*/
        T * get(int index) {
            return &self[index];
        }

        /**Tells you the index position of a specific element
         * @param e element to check
         * @returns int between 0 - size(), or -1 if it isn't in this ArrayList*/
        int indexOf(T e) {
            for(int i=0; i<self.size(); i++) {
                if(&self[i] == &e) return i;
            }
            return -1;
        }

        /**Checks if ArrayList is empty, you can also check if size() == 0
         * @returns true if empty, otherwise false if there are elements in this ArrayList*/
        boolean isEmpty() {
            return ((self.size() == 0) ? true : false);
        }

        /**Tells you the last index position of a specific element
         * @param e element to check
         * @returns int between 0 - size(), or -1 if it isn't in this ArrayList*/
        int lastIndexOf(T e) {
            for(int i=self.size(); i>0; i--) {
                if(&self[i] == &e) return i;
            }
            return -1;
        }

        /**Removes an element from the ArrayList
         * @param index spot to remove from*/
        void remove(int index) {
            self.erase(self.begin()+index);
        }

        //remove by element is removed from this as it coincides with int

        /**Removes a group of elementsfrom the ArrayList from a start index to end index
         * @param start starting spot to remove from
         * @param end ending point to remove from */
        void removeRange(int start, int end) {
            self.erase(self.begin()+start, self.begin()+end);
        }

        /**Sets a spot in the ArrayList to something new
         * @param index spot to change
         * @param e element to set*/
        void set(int index, T e) {
            self[index] = e;
        }

        /**Gives you the size of the ArrayList (how many elements in it)
         * @returns amount of elements inside*/
        int size() {
            return self.size();
        }

        /**Converts ArrayList into an array
         * @returns array of all elements in ArrayList */
        T * toArray() {
            T r[self.size()];
            for(int i=0; i<self.size(); i++) {
                r[i] = self[i];
            }

            return r;
        }
        
        //void trimToSize(); //TODO

        /**Applies a function to all elements in ArrayList
         * @param *fp name of function to apply
         * @returns pointer to this ArrayList */
        ArrayList<T> * map(T (*fp)(T)) {
            for(int i=0; i<this->size(); i++)
                this->set(i, ((*fp)(*(this->get(i)))));
            return this;
        }

        /**Removes elements from ArrayList who do not meet condition of function
         * @param *fp name of function to compare elements to(boolean)
         * @returns pointer to this ArrayList */
        ArrayList<T> * filter(boolean (*fp)(T)) {
            ArrayList<T> out;
            for(int i=0; i<this->size(); i++)
                if(((*fp)(*(this->get(i))))) out.add(*(this->get(i)));
            this->self = out.self;
            return this;
        }

        /**Populates ArrayList by calling function from 0 -> n
         * @param *fp name of function to apply
         * @param n amount to add (usually int)
         * @returns pointer to this ArrayList */
        template <typename U>
        ArrayList<T> * populate(T (*fp)(U), U n) {
            assert(n >= 0);
            for(U i=0; i<n; i++)
                this->add(((*fp)(i)));
            return this;
        }

        /**Calls function with element as parameter
         * @param *fp name of function to call
         * @returns pointer to this ArrayList */
        template <typename U>
        ArrayList<T> * foreach(U (*fp)(T)) {
            for(int i=0; i<this->size(); i++)
                ((*fp)(*(this->get(i))));
            return this;
        }

        /**Calls function without breaking chain
         * @param *fp name of function to call
         * @returns pointer to this ArrayList */
        template <typename U>
        ArrayList<T> * call(U (*fp)()) {
            (*fp);
            return this;
        }

        /**Calls function without breaking chain, sends pointer of ArrayList to it
         * @param *fp name of function to call
         * @returns pointer to this ArrayList */
        template <typename U, typename V>
        ArrayList<T> * callback(U (*fp)(V)) {
            (*fp)(this);
            return this;
        }
    };
}

#endif