#pragma once            // PERF_MEASURE_H

#include <utility>
#include <functional>
#include <chrono>
#include <iostream>
#include <type_traits>

typedef std::chrono::time_point<std::chrono::system_clock> marktime;

template <class F, F f> struct wrapper_impl;


template <class R, class... Args, R(*f)(Args...)>
/* Here the variadics are used to capture the function signature,
   so that the wrapper can be used with any function signature.
   The variadics are not used in the implementation. */
struct wrapper_impl<R(*)(Args...), f> {
    /* The wrapper is a function object, so that it can be used
       with std::function. */
    static R wrapper(Args&&... args) {
        /* The wrapper forwards the arguments to the wrapped function,
        * and returns the result. */
        auto start = std::chrono::high_resolution_clock::now();
        // Transfere the property of the arguments to the wrapped function.
        //R res = f(std::forward<Args>(args)...);               /* Under the hood the static_cast is a no-op, but it is needed :
                                                                /* Args&& forward(typename std::remove_reference<Args>::type& args...) noexcept {
                                                                *   return static_cast<Args&&>(args...);
                                                                * } 
                                                                * However, the function doesn't work with class pointer, and doesn't take multiple class member */

        R res = std::invoke(f, std::forward<Args>(args)...);    /* std::invoke is a C++17 feature, and it is a no-op for function pointer :
                                                                 * template <typename F, typename... Args>
                                                                 * decltype(auto) invoke(F&& f, Args&&... args) noexcept(
                                                                 *      noexcept(std::forward<F>(f)(std::forward<Args>(args)...))) {
                                                                 *      return std::forward<F>(f)(std::forward<Args>(args)...);
                                                                 * }
                                                                 * For this example, this is the perfect usage because it's more generic for templates usage */
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << " seconds\n";

        return std::is_same<R, void>::value ? R() : res;
    }
}; 


// Helper constexpr variable to simplify usage of the wrapper
template <class F, F f> 
constexpr auto wrapper = wrapper_impl<F, f>::wrapper;

// Usage:
// wrapper<decltype(&foo), foo>	