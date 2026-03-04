#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class GameOver {
    public:
        GameOver();
        bool run();

    private:
        // Window
        sf::RenderWindow* window;
        void initwindow();

        // Variables
        sf::Font font;
        std::unique_ptr<sf::Text> gameOverText;
        int height;
        int width;
};