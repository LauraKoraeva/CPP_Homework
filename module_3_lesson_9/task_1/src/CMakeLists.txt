cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(elfForest
	main.cpp 
	${MY_INCLUDE_DIR}/Branch.h 
	Branch.cpp
	${MY_INCLUDE_DIR}/treeFunctions.h 
	treeFunctions.cpp
)
target_include_directories(elfForest PUBLIC ${MY_INCLUDE_DIR})