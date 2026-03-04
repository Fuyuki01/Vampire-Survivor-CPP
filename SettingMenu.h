#pragma once
#include <SFML/Graphics.hpp>

class MainMenu;

class SettingMenu{
    public:
        // Constructor and main loop
        SettingMenu(MainMenu* mainMenu);
        void run();

    private:
        // Window
        sf::RenderWindow* window;
        void initWindow();

        void initMenuItems();

        void updateSelectionVisual();
        void updateMenuItems();

        // Variables
        sf::Font font;
        std::vector<sf::Text> items;
        int selected = 0;
        int height;
        int width;
        int musicVolume;
        bool musicON;
        MainMenu* mainMenuPointer;
};