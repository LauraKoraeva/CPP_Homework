cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Matches
	main.cpp 
	utility.cpp
	${MY_INCLUDE_DIR}/utility.h 
	conditions.cpp 
	${MY_INCLUDE_DIR}/conditions.h 
	players.cpp 
	${MY_INCLUDE_DIR}/players.h 
	gameplay.cpp 
	${MY_INCLUDE_DIR}/gameplay.h 
)
target_include_directories(Matches PUBLIC ${MY_INCLUDE_DIR})