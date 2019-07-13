cmake_minimum_required(VERSION 3.12)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES GameCharacter.h GameCharacter.cpp Ammo.cpp Ammo.h Weapon.cpp Weapon.h Usable.cpp Usable.h MedKit.cpp MedKit.h Interactable.cpp Interactable.h Trampoline.cpp Trampoline.h Granade.cpp Granade.h Barrier.cpp Barrier.h Map.cpp Map.h Terrain.cpp Terrain.h Attachment/LongBarrel.cpp Attachment/LongBarrel.h Attachment/PowerBarrel.cpp Attachment/PowerBarrel.h Attachment/ExtendedMagazine.cpp Attachment/ExtendedMagazine.h Attachment/LaserScope.cpp Attachment/LaserScope.h Enemy.cpp Enemy.h SpecialAttack/SpecialAttack.h Factory/WeaponFactory.h Factory/WeaponFactory.cpp Factory/EnemyFactory.cpp Factory/EnemyFactory.h SpecialAttack/Charge.cpp SpecialAttack/Charge.h SpecialAttack/Kamikaze.cpp SpecialAttack/Kamikaze.h Box.h SpecialAttack/BossAttack.cpp SpecialAttack/BossAttack.h Behaviour.cpp Behaviour.h)
set(SFML usr/include/SFML/)
set(SFML_STATIC_LIBRARIES TRUE)
link_directories(SFML)
include_directories(SFML)
include_directories(${SFML_INCLUDE_DIR})

add_subdirectory(test)
add_executable(MetalCFU main.cpp ${SOURCE_FILES} Factory/TerrainFactory.cpp Factory/TerrainFactory.h Behaviour.cpp Behaviour.h)

add_library(core ${SOURCE_FILES} )
target_link_libraries(MetalCFU core sfml-graphics sfml-window sfml-system sfml-audio)