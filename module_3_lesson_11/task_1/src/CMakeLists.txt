cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Superdog
	main.cpp 
	animals.cpp 
	${MY_INCLUDE_DIR}/animals.h 
	talents.cpp 
	${MY_INCLUDE_DIR}/talents.h 
	utility.cpp 
	${MY_INCLUDE_DIR}/utility.h 
)
target_include_directories(Superdog PUBLIC ${MY_INCLUDE_DIR})