#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Enemy{
    public:
        explicit Enemy(Player* player);
        virtual ~Enemy() = default;

        void update();
        void render();

        void updateAppearance();
        sf::RectangleShape rectangle;
    
        sf::Rect<float> returnBounds();

        float returnAttackTime();
        void restartAttackTime();


    private:
        float enemySpeed;
        sf::Vector2f enemySize;
        sf::Vector2f enemyInitPosition;

        sf::Clock attackClock;

        float hitFrame;

        Player* playerPointer;

        sf::Vector2f decidedirection();
        void advanceposition();
};