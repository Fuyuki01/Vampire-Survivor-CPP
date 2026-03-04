#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class MainMenu {
    public:
        // Constructor and main loop
        MainMenu();
        int run();

        void updateSound(int musicVolume, bool musicOn);

        int returnVolume();

    private:
        // window
        sf::RenderWindow* window;
        sf::Music music;
        
        void updateSelectionVisual();
        
        void initwindow();
        void initMenuItems();
        void initMusic();

        // Variables
        sf::Font font;
        std::vector<sf::Text> items;
        int selected = 0;
        int width;
        int height;
        int musicVolume;
};