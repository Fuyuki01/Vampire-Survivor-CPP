#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class GameOver {

public:
GameOver();
bool run();


private:
    sf::RenderWindow* window;
    void initwindow();

    sf::Font font;
    std::unique_ptr<sf::Text> gameOverText;
    int height;
    int width;

};