cmake_minimum_required(VERSION 3.12)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SOURCE_FILES runAllTests.cpp  GameCharacterTests.cpp MedKitTests.cpp GranadeTest.cpp WeaponTest.cpp ../Barrier.cpp ../Barrier.h ../Map.cpp ../Map.h ../Terrain.cpp ../Terrain.h AttachmentTest.cpp InventoryTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})

target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)