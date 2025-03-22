cmake_minimum_required(VERSION 3.17)
project(movies)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(movies main.cpp createDatabase.cpp createDatabase.h)

target_link_libraries(movies PRIVATE nlohmann_json::nlohmann_json)