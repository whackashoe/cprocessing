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

        ArrayList<T>& operator= (const ArrayList<T>& a) {
            this->a = a.self;
            return (*this);
        }

        bool operator== (const ArrayList<T>& a)      { 
            return ((this->self == a.self) ? true : false);
        }

        bool operator!= (const ArrayList<T>& a)      { 
            return ((this->self != a.self) ? true : false);
        }

        ArrayList<T>& operator+ (const ArrayList<T>& a) {
            ArrayList<T> temp;
            temp = *(this);
            for(int i=0; i<a.size(); i++) {
                temp->add(*(a.get(i)));
            }
            return (*temp);
        }

        ArrayList<T>& operator+= (const ArrayList<T>& a) {
            for(int i=0; i<a.size(); i++) {
                this->add(*(a.get(i)));
            }
            return (*this);
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

        T * head() {
            assert(size() > 0);
            return &get(0);
        }

        T * last() {
            assert(size() > 0);
            return &get(size()-1);
        }

        /*T * minimum() {   //TODO
            assert(size() > 0);
        }*/

        /*T * maximum() {   //TODO
            assert(size() > 0);
            return &get(size()-1);
        }*/

        T sum() {
            assert(size() > 0);
            T r = *(this->get(0));
            for(int i=1; i<this->size(); i++) r = r+*(this->get(i));
            return r;
        }

        T product() {
            assert(size() > 0);
            T r = *(this->get(0));
            for(int i=1; i<this->size(); i++) r = r*(*(this->get(i)));
            return r;
        }

        ArrayList<T> tail() {
            ArrayList<T> out(((this->size() > 0) ? (this->size()-1) : 0));
            for(int i=1; i<this->size(); i++) out.add(*(this->get(i)));

            return out;
        }

        ArrayList<T> init() {
            ArrayList<T> out(((this->size() > 0) ? (this->size()-1) : 0));
            for(int i=0; i<this->size()-1; i++) out.add(*(this->get(i)));

            return out;
        }

        ArrayList<T> reverse() {
            ArrayList<T> out(this->size());
            for(int i=this->size(); i>0; i--) out.add(*(this->get(i)));

            return out;
        }

        ArrayList<T> take(int n) {
            ArrayList<T> out(n);
            for(int i=0; i<n; i++) out.add(*(this->get(i)));

            return out;
        }

        ArrayList<T> drop(int n) {
            ArrayList<T> out(this->size() - n);
            for(int i=n; i<this->size(); i++) out.add(*(this->get(i)));

            return out;
        }
    };
}

#endif