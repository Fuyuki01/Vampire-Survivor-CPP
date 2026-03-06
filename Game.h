#pragma once
#include <SFML/Graphics.hpp>

class Enemy;
class Player;
class Map;
class Settings;
class GameOver;

class Game{
    public:
        // Constructors 
        Game(Settings* settings);
        ~Game();

        // Functions
        void pollevents();
        void update();
        void render();
        
        // Getters
        bool windowIsOpen() const;
        bool isTotalDeath() const { return totalDeath; }
        
    private:
        // Values
        std::vector<Enemy*> enemies;
        bool totalDeath;
        Settings* settingsPointer;

        // Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        Player* player;

        // Enemy Spawn
        sf::Clock enemySpawnerTime;
        void enemyAutomaticSpawn();
        
        // Camera
        sf::View view;

        // Map
        Map* worldMap;

        // Private Functions
        void initVariables();
        void initWindow();
        void initView();
        void initMap();
};