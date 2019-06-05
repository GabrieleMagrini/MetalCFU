cmake_minimum_required(VERSION 3.13)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp)
add_executable(runAllTests ${SOURCE_FILES})

target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)