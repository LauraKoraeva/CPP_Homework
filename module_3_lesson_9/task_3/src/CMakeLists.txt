cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Company
	main.cpp 
	${MY_INCLUDE_DIR}/Employee.h 
	Employee.cpp
	${MY_INCLUDE_DIR}/ChiefExecutive.h 
	ChiefExecutive.cpp
	${MY_INCLUDE_DIR}/Manager.h 
	Manager.cpp
	${MY_INCLUDE_DIR}/TeamMember.h 
	TeamMember.cpp
	${MY_INCLUDE_DIR}/WorkType.h 
	WorkType.cpp 
	${MY_INCLUDE_DIR}/Utility.h 
	Utility.cpp
)
target_include_directories(Company PUBLIC ${MY_INCLUDE_DIR})