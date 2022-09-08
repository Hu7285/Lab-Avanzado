cmake_minimum_required(VERSION 3.10)

project(Clas03)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(Tarea ${sources} class03.cpp)
