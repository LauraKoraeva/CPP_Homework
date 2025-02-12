cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Player
	main.cpp 
	player.cpp 
	${MY_INCLUDE_DIR}/player.h 
	utility.cpp 
	${MY_INCLUDE_DIR}/utility.h 
)
target_include_directories(Player PUBLIC ${MY_INCLUDE_DIR})