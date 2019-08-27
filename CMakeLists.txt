cmake_minimum_required (VERSION 2.6)

project (AP_cmake)

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(include)

add_executable(exe 
	src/main.cpp 
	src/tictac.cpp
	include/tictac.hpp
)