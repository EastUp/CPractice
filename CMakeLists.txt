cmake_minimum_required(VERSION 3.16)
project(CPractice)

set(CMAKE_CXX_STANDARD 14)

#add_executable(CPractice sample/15.c++sample.cpp sample/15.Student.cpp)
add_executable(CPractice sample/26.datastructuresandalgorithms.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")