#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class Enemy;
class Player;
class Card;
class Map;
class Settings;
class GameOver;

enum class GameState{
    Playing,
    LevelUp
};

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
        bool totalDeath;
        Settings* settingsPointer;
        std::random_device rd;
        std::mt19937 gen;
        GameState gameState;
        sf::Keyboard::Scancode lastKeyPressed;

        // Vectors
        std::vector<Enemy*> enemies;
        std::vector<std::unique_ptr<Card>> cardPool;
        std::vector<Card*> currentCards;

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

        // Collision
        void enemyCollision();

        // Player Collision
        void playerCollision();

        // Private Functions
        void initVariables();
        void initWindow();
        void initView();
        void initMap();
        void initCards();
        void get3Cards();
        void positionCards();
        
        // Game State Updates
        void updatePlaying();
        void updateLevelUp();

};