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

    private:
        sf::RectangleShape shape;
        void initShape();
        float speed;
};