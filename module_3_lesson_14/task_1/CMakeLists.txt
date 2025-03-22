cmake_minimum_required(VERSION 3.17)
project(rush)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(rush main.cpp)

target_link_libraries(rush PRIVATE nlohmann_json::nlohmann_json)