cmake_minimum_required(VERSION 3.12)
project(MetalCFU)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES GameCharacter.h GameCharacter.cpp Ammo.cpp Ammo.h Weapon.cpp Weapon.h Usable.cpp Usable.h MedKit.cpp MedKit.h Interactable.cpp Interactable.h Trampoline.cpp Trampoline.h Granade.cpp Granade.h Barrier.cpp Barrier.h Map.cpp Map.h Terrain.cpp Terrain.h Attachment/LongBarrel.cpp Attachment/LongBarrel.h Attachment/PowerBarrel.cpp Attachment/PowerBarrel.h Attachment/ExtendedMagazine.cpp Attachment/ExtendedMagazine.h Attachment/LaserScope.cpp Attachment/LaserScope.h Enemy.cpp Enemy.h Factory/WeaponFactory.h Factory/WeaponFactory.cpp Factory/EnemyFactory.cpp Factory/EnemyFactory.h Behaviour/Behaviour.cpp Behaviour/Behaviour.h Factory/TerrainFactory.cpp Factory/TerrainFactory.h GameState/GameState.h GameState/MainMenuState.cpp GameState/MainMenuState.h GameState/GameState.cpp GameState/IllegalStateException.cpp GameState/IllegalStateException.h Game.cpp Game.h GameState/GameOverState.cpp GameState/GameOverState.h GameState/OptionMenuState.cpp GameState/OptionMenuState.h GameState/StartGameState.cpp GameState/StartGameState.h GameState/PauseGameState.cpp GameState/PauseGameState.h GameState/ExitGameState.cpp GameState/ExitGameState.h GUI/Button.cpp GUI/Button.h GUI/MainMenu.cpp GUI/MainMenu.h GUI/OptionMenu.cpp GUI/OptionMenu.h GUI/PauseMenu.cpp GUI/PauseMenu.h utility/BitmapFile.cpp utility/BitmapFile.h)
set(SFML usr/include/SFML/)
set(SFML_STATIC_LIBRARIES TRUE)
link_directories(SFML)
include_directories(SFML)
include_directories(${SFML_INCLUDE_DIR})

add_subdirectory(test)
add_executable(MetalCFU main.cpp ${SOURCE_FILES})

add_library(core ${SOURCE_FILES} Behaviour/patrolBehaviour.cpp Behaviour/patrolBehaviour.h Behaviour/attackBehaviour.cpp Behaviour/attackBehaviour.h Behaviour/suicidalBehaviour.cpp Behaviour/suicidalBehaviour.h)
target_link_libraries(MetalCFU core sfml-graphics sfml-window sfml-system sfml-audio)