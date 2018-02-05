include_directories(../src)
include(../src/CMakeHelpers.cmake)

CheckLibrary()

add_executable(ccr-test fmtseq.cpp)

LinTargetLibrary(ccr-test)
target_link_libraries(ccr-test codecrypt)