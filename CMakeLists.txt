cmake_minimum_required(VERSION 3.13)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES GameCharacter.h GameCharacter.cpp Ammo.cpp Ammo.h Weapon.cpp Weapon.h Usable.cpp Usable.h MedKit.cpp MedKit.h Interactable.cpp Interactable.h Trampoline.cpp Trampoline.h)

add_subdirectory(test)
add_executable(MetalCFU main.cpp ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})
target_link_libraries(MetalCFU core)