cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Computer
	main.cpp 
	phonebook.cpp 
	${MY_INCLUDE_DIR}/phonebook.h 
	phone.cpp 
	${MY_INCLUDE_DIR}/phone.h 
	utility.cpp 
	${MY_INCLUDE_DIR}/utility.h 
)
target_include_directories(Computer PUBLIC ${MY_INCLUDE_DIR})