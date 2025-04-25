cmake_minimum_required(VERSION 3.31)

project(
	compile_with_module_std
	VERSION 0.0.1
	LANGUAGES CXX)

# hack #1: temporary hack for GCC g++15.0 HEAD https://www.equation.com gcc-15-20250420-64.exe
# to remove when g++ & CMake know about module std
add_library(module_std)

target_sources(module_std
	PUBLIC
		FILE_SET CXX_MODULES FILES
			gnu/std.cc # modified from MinGW\include\c++\16.0.0\bits\std.cc
)
target_compile_features(module_std PUBLIC cxx_std_26)
# also to remove (see below):
# target_link_libraries(...XYZ... PRIVATE module_std)

# hack #2: advanced features like std::print(), std::stacktrace, etc in g++14 and g++15.0 HEAD:
# target_link_libraries(...XYZ... PRIVATE stdc++exp)

add_library(my_module)

target_sources(my_module
	PUBLIC
		FILE_SET CXX_MODULES FILES
			src/my_module.cpp 
)
target_compile_features(my_module PUBLIC cxx_std_26)
target_link_libraries(my_module PRIVATE module_std) # hack #1

add_executable(demo src/demo.cpp)
target_compile_features(demo PUBLIC cxx_std_26)
target_link_libraries(demo PRIVATE my_module)
target_link_libraries(demo PRIVATE module_std) # hack #1
target_link_libraries(demo PRIVATE stdc++exp)  # hack #2

			
			
 

