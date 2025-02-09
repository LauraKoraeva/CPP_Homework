cmake_minimum_required(VERSION 3.31)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Computer
	main.cpp 
	ram.cpp 
	${MY_INCLUDE_DIR}/ram.h 
	gpu.cpp 
	${MY_INCLUDE_DIR}/gpu.h 
	disk.cpp 
	${MY_INCLUDE_DIR}/disk.h 
	cpu.cpp 
	${MY_INCLUDE_DIR}/cpu.h 
	kbd.cpp 
	${MY_INCLUDE_DIR}/kbd.h 
)
target_include_directories(Computer PUBLIC ${MY_INCLUDE_DIR})