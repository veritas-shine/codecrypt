cmake_minimum_required(VERSION 3.8)
project(ccr)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DPACKAGE_VERSION="1.8")

add_subdirectory(src)
add_subdirectory(test)

CheckLibrary()

add_executable(ccr src/main.cpp)

LinTargetLibrary(ccr)
target_link_libraries(ccr codecrypt)