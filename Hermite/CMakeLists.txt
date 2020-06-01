cmake_minimum_required(VERSION 3.15)
project(Hermite)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hermite main.cpp Polynomial.cpp Polynomial.h Hermite.h Hermite.cpp)