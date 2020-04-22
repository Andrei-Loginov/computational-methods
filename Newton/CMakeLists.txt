cmake_minimum_required(VERSION 3.15)
project(Newton)

set(CMAKE_CXX_STANDARD 14)

add_executable(Newton main.cpp Polynomial.h Polynomial.cpp Newton.h Newton.cpp)