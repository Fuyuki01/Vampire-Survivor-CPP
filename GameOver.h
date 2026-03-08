#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Settings;

class GameOver {
    public:
        GameOver(Settings* settings);
        ~GameOver();
        bool run();

    private:
        // Window
        sf::RenderWindow* window;
        void initwindow();
        
        void initMenuItems();

        // Variables
        sf::Font font;
        std::unique_ptr<sf::Text> gameOverText;
        int height;
        int width;
        Settings* settingsPointer;
};