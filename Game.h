#pragma once
#include <SFML/Graphics.hpp>

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
        // Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        
        // Private Functions
        void initVariables();
        void initWindow();

};