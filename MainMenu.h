#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MainMenu {
public:
    // Constructor and main loop
    MainMenu();
    bool run();

private:
    void updateSelectionVisual();

    // Variables
    sf::Font font;
    std::vector<sf::Text> items;
    int selected = 0;
    int width;
    int height;
};