cmake_minimum_required(VERSION 3.16)
project(zadanie2)

set(CMAKE_CXX_STANDARD 17)

add_executable(zadanie2 main.cpp bignum.cc header/bignum.h header/bits.h header/hostint.h header/wideint.h)
