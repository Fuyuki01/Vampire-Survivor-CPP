cmake_minimum_required(VERSION 3.16)
project(VampireSurvivor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ASSETS "../assets/*")

file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
find_package(SFML 3.0 COMPONENTS Audio Graphics Window System)

add_executable(game
    main.cpp
    Game.cpp
    Player.cpp
    Map.cpp
    Enemy_Folder/Enemy.cpp
    Enemy_Folder/Enemy_Troll.cpp
    Enemy_Folder/Enemy_Humongous.cpp
    Enemy_Folder/Enemy_Goblin.cpp
    Cards_Folder/Card.cpp
    Cards_Folder/Damage_Card.cpp
    Cards_Folder/Health_Card.cpp
    Cards_Folder/Speed_Card.cpp
    Menu_Folder/MainMenu.cpp
    GameOver.cpp
    Menu_Folder/SettingMenu.cpp
    HealthBar.cpp
    XPBar.cpp
    Weapon.cpp
    Sword.cpp
)

target_link_libraries(game PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)