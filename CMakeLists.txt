cmake_minimum_required(VERSION 3.13)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)

add_executable(MetalCFU main.cpp GameCharacter.h GameCharacter.cpp Ammo.cpp Ammo.h Weapon.cpp Weapon.h Usable.cpp Usable.h)
