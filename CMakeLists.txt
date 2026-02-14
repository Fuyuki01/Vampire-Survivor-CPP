cmake_minimum_required(VERSION 3.16)
project(VampireSurvivor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ASSETS "../assets/*")

file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(game
    main.cpp
    Game.cpp
    Player.cpp
    Map.cpp
    Enemy.cpp
    Enemy_Troll.cpp
    MainMenu.cpp
    HealthBar.cpp
)

target_link_libraries(game
    SFML::Graphics
    SFML::Window
    SFML::System
)