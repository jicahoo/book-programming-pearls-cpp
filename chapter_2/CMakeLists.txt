cmake_minimum_required(VERSION 3.15)
project(cmake_hello_world)
find_package(Boost 1.65.1 REQUIRED)
message("zhangj52: ${Boost_FOUND}")
message("boost include dirs: ${Boost_INCLUDE_DIRS}")
message("boost lib dirs: ${Boost_LIBRARY_DIRS}")
message("boost libs: ${Boost_LIBRARIES}")

set(CMAKE_CXX_STANDARD 98)

add_executable(hello_world main.cpp)
