cmake_minimum_required(VERSION 3.17)
project("HTTP Requests" VERSION 1)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG dec9422db3af470641f8b0d90e4b451c4daebf64) 
FetchContent_MakeAvailable(cpr)

add_executable(HTTP_Requests main.cpp)
target_link_libraries(HTTP_Requests PRIVATE cpr::cpr)
