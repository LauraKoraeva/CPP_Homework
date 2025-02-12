cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Screen
	main.cpp 
	screen.cpp 
	${MY_INCLUDE_DIR}/screen.h 
	window.cpp 
	${MY_INCLUDE_DIR}/window.h 
	utility.cpp 
	${MY_INCLUDE_DIR}/utility.h 
)
target_include_directories(Screen PUBLIC ${MY_INCLUDE_DIR})