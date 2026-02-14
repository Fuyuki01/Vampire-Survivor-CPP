#pragma once
#include <SFML/Graphics.hpp>

class Enemy;
class Player;
class Map;

class Game{
    public:
        // Constructors 
        Game();
        ~Game();

        // Functions
        void pollevents();
        void update();
        void render();
        
        // Getters
        bool windowIsOpen() const;

    private:
        // Values
        std::vector<Enemy*> enemies;

        // Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        Player* player;

        // Camera
        sf::View view;

        // Map
        Map* worldMap;

        // Private Functions
        void initVariables();
        void initEnemies();
        void initWindow();
        void initView();
        void initMap();
};