cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Shapes
	main.cpp 
	${MY_INCLUDE_DIR}/Shape.h 
	Shape.cpp
	${MY_INCLUDE_DIR}/BoundingBox.h 
	BoundingBox.cpp
	${MY_INCLUDE_DIR}/Circle.h 
	Circle.cpp
	${MY_INCLUDE_DIR}/Triangle.h 
	Triangle.cpp
	${MY_INCLUDE_DIR}/Square.h 
	Square.cpp 
	${MY_INCLUDE_DIR}/Rectangle.h 
	Rectangle.cpp
	${MY_INCLUDE_DIR}/Colours.h 
	Colours.cpp 
	${MY_INCLUDE_DIR}/Utility.h 
	Utility.cpp
)
target_include_directories(Shapes PUBLIC ${MY_INCLUDE_DIR})