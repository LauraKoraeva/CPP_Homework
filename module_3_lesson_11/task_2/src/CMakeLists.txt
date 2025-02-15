cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Shapes
	main.cpp 
	${MY_INCLUDE_DIR}/shape.h 
	circle.cpp 
	${MY_INCLUDE_DIR}/circle.h 
	triangle.cpp 
	${MY_INCLUDE_DIR}/triangle.h 
	rectangle.cpp 
	${MY_INCLUDE_DIR}/rectangle.h 
)
target_include_directories(Shapes PUBLIC ${MY_INCLUDE_DIR})