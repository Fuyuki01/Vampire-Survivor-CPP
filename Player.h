#pragma once
#include <SFML/Graphics.hpp>

class HealthBar;

class Player {
    public:
        // Constructors
        Player();
        ~Player();

        void update();
        void render(sf::RenderTarget* target);
        void keyInputs();
        void getDamaged(float damage);

        float returnHealth();
        sf::Vector2f returnPosition();
        sf::Rect<float> returnBounds();

    private:
        sf::RectangleShape shape;
        void initShape();
        float speed;

        // Health
        float health;
        HealthBar* healthBar;
        void initHealthBar();
};