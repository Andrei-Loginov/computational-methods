cmake_minimum_required(VERSION 3.15)
project(runge_function_approximation)

set(CMAKE_CXX_STANDARD 14)

add_executable(runge_function_approximation main.cpp Polynomial.h Polynomial.cpp Newton.h Newton.cpp Runge_func_approx.h Runge_func_approx.cpp)