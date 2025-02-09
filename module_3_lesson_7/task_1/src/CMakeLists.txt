cmake_minimum_required(VERSION 3.17)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Operation main.cpp instruments.cpp coordinates.cpp utility.cpp ${MY_INCLUDE_DIR}/instruments.h ${MY_INCLUDE_DIR}/coordinates.h ${MY_INCLUDE_DIR}/utility.h)
target_include_directories(Operation PUBLIC ${MY_INCLUDE_DIR})