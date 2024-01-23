#include <utility>
#include <functional>
#include <chrono>
#include <iostream>

typedef std::chrono::time_point<std::chrono::system_clock> marktime;

template<class F, F f> struct wrapper_impl;
template<class R, class... Args, R(*f)(Args...)> //Declaration of variadic function arguments to passe through the wrapper
struct wrapper_impl<R(*)(Args...), f> { //Use of variadic function arguments to passe through the wrapper
	static R wrapper(Args... args) {
		return f(args...);
	}
};

template<class F, F f>
constexpr auto wrapper = wrapper_impl<F, f>::wrapper;

/*
* Here the decltype must be used to avoid variadic type conflict, 
* to be sure the function we wrapped has the type that has been 
* passed to template argument.
*/
// wrapper<decltype(&foo), foo>	

void perf_mes(std::function<int(void)>& F) {
	marktime start, end;
	
	start = std::chrono::system_clock::now();
	F();
	end = std::chrono::system_clock::now();

	auto execution_time = end - start;

	std::cout << execution_time << "s" << "\n"; //avoid flushing the buffer here, can cause slower performance if perf_mes is done to many.
}