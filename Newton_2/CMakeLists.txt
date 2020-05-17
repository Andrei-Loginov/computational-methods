cmake_minimum_required(VERSION 3.15)
project(Newton_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Newton_2 main.cpp Polynomial.h Polynomial.cpp Newton.h Newton.cpp)