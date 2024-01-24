#pragma once            // PERF_MEASURE_H

#include <utility>
#include <functional>
#include <chrono>
#include <iostream>

typedef std::chrono::time_point<std::chrono::system_clock> marktime;

template <class F, F f> 
struct wrapper_impl;

template <class R, class... Args, R(*f)(Args...)>
struct wrapper_impl<R(*)(Args...), f> {
    static R wrapper(Args&&... args) {
        auto start = std::chrono::high_resolution_clock::now();
        R res = f(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << " seconds\n";
        return res;
    }
};

// Helper constexpr variable to simplify usage of the wrapper
template <class F, F f> 
constexpr auto wrapper = wrapper_impl<F, f>::wrapper;

// Usage:
// wrapper<decltype(&foo), foo>	