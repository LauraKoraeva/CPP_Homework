cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(TicTacToe
	main.cpp 
	${MY_INCLUDE_DIR}/Config.h 
	Config.cpp
	${MY_INCLUDE_DIR}/Statistics.h 
	Statistics.cpp
	${MY_INCLUDE_DIR}/Session.h 
	Session.cpp
	${MY_INCLUDE_DIR}/Timer.h 
	Timer.cpp
	${MY_INCLUDE_DIR}/UI.h 
	UI.cpp 
)
target_include_directories(TicTacToe PUBLIC ${MY_INCLUDE_DIR})