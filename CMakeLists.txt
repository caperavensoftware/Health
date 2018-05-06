# cmake_minimum_required(VERSION <specify CMake version here>)
project(Health)

set(CMAKE_CXX_STANDARD 11)

add_executable(Health main.cpp Health.cpp Health.h)