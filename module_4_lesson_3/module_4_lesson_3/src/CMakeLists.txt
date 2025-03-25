cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Title
	main.cpp 
	${MY_INCLUDE_DIR}/1.h 
	1.cpp
	${MY_INCLUDE_DIR}/2.h 
	2.cpp
	${MY_INCLUDE_DIR}/3.h 
	3.cpp
	${MY_INCLUDE_DIR}/4.h 
	4.cpp
	${MY_INCLUDE_DIR}/5.h 
	5.cpp 
	${MY_INCLUDE_DIR}/Utility.h 
	Utility.cpp
)
target_include_directories(Title PUBLIC ${MY_INCLUDE_DIR})