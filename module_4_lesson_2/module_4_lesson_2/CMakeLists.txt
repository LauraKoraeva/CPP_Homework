cmake_minimum_required(VERSION 3.17)
project("Matches" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(GameLibrary STATIC 
    lib/conditions.cpp
    lib/players.cpp
    lib/gameplay.cpp
    lib/utility.cpp
)

add_executable(Matches src/main.cpp)

target_link_libraries(Matches GameLibrary)

target_include_directories(Matches PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
