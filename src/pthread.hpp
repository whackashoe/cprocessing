#include "cprocessing.hpp"


#ifndef CPROCESSING_PTHREAD_
#define CPROCESSING_PTHREAD_


using namespace cprocessing;
/*
namespace cprocessing {
    template<typename T>
	class PThread {
	public:
		std::thread self;

		PThread();
		void callable_method(int x);
		void thread_wrapper(T callable) {
			callable();
		}

		std::thread make_thread_wrapper(T callable) {
			return std::thread(&thread_wrapper<T>, std::forward<T>(callable));
		}
};
*/

#endif
