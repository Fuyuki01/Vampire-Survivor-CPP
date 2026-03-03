#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class MainMenu {
public:
    // Constructor and main loop
    MainMenu();
    bool run();

private:
    // window
    sf::RenderWindow* window;
    sf::Music music;
    
    void updateSelectionVisual();
    
    void initwindow();


    // Variables
    sf::Font font;
    std::vector<sf::Text> items;
    int selected = 0;
    int width;
    int height;
};