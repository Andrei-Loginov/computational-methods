cmake_minimum_required(VERSION 3.15)
project(backward_interpolation)

set(CMAKE_CXX_STANDARD 14)

add_executable(backward_interpolation main.cpp Polynomial.cpp Polynomial.h Newton.h Newton.cpp Backward_interpolation.cpp Backward_interpolation.h)