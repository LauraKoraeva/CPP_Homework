cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Smart_Toy
	main.cpp 
	${MY_INCLUDE_DIR}/dog.h 
	dog.cpp
	${MY_INCLUDE_DIR}/toy.h 
	toy.cpp
)
target_include_directories(Smart_Toy PUBLIC ${MY_INCLUDE_DIR})