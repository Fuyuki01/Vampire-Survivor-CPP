#pragma once
#include <SFML/Graphics.hpp>

class Player {
    public:
        // Constructors
        Player();
        ~Player() = default;

        void update();
        void render(sf::RenderTarget* target);
        void keyInputs();
        sf::Vector2f returnPosition();
        sf::Rect<float> returnBounds();

    private:
        sf::RectangleShape shape;
        void initShape();
        float speed;
};