cmake_minimum_required(VERSION 3.12)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES GameCharacter.h GameCharacter.cpp Ammo.cpp Ammo.h Weapon.cpp Weapon.h Usable.cpp Usable.h MedKit.cpp MedKit.h Interactable.cpp Interactable.h Trampoline.cpp Trampoline.h Granade.cpp Granade.h Barrier.cpp Barrier.h Map.cpp Map.h Terrain.cpp Terrain.h Attachment/LongBarrel.cpp Attachment/LongBarrel.h Attachment/PowerBarrel.cpp Attachment/PowerBarrel.h Attachment/ExtendedMagazine.cpp Attachment/ExtendedMagazine.h Attachment/LaserScope.cpp Attachment/LaserScope.h Enemy.cpp Enemy.h SpecialAttack.cpp SpecialAttack.h)

add_subdirectory(test)
add_executable(MetalCFU main.cpp ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})
target_link_libraries(MetalCFU core)