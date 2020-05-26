cmake_minimum_required(VERSION 3.0)

set (my_project "IO-Benchmarks-C++")

project(my_project)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#this alows use to run the executables made after the `make install` command is executed by the user
set(CMAKE_MACOSX_RPATH 1)
# the RPATH to be used when installing
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_subdirectory(tests)

add_library(io_perf SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/IO_perf.cc)

target_include_directories(io_perf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

install(TARGETS io_perf LIBRARY DESTINATION lib)