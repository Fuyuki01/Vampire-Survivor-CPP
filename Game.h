#pragma once
#include <SFML/Graphics.hpp>


class Player;

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
        Player* player;
        // Private Functions
        void initVariables();
        void initWindow();

};