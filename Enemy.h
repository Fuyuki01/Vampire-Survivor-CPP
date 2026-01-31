#pragma once
#include <SFML/Graphics.hpp>

class Enemy{
    public:
        explicit Enemy();
        virtual ~Enemy() = default;

        void updateAppearance();

        sf::RectangleShape rectangle;

    private:
        float enemySpeed;
        sf::Vector2f enemySize;
        sf::Vector2f enemyPosition;
};