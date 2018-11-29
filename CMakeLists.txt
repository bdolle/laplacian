cmake_minimum_required(VERSION 3.9)
project(Laplace2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Laplace2 main.cpp relax.h cmake-build-debug/relax.cpp)