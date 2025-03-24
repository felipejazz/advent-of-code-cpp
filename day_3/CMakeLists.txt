cmake_minimum_required(VERSION 3.10)
project(Day3)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../common) 

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)