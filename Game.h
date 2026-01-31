#pragma once
#include <SFML/Graphics.hpp>

class Enemy;

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
        std::vector<Enemy*> enemyVector;

        // Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        
        // Private Functions
        void initVariables();
        void initEnemies();
        void initWindow();

};