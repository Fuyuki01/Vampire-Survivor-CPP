#pragma once
#include <SFML/Graphics.hpp>

class HealthBar: public sf::RectangleShape {
    public:
        HealthBar(float health);
        ~HealthBar();

        void updateHealth(float health);
        void render(sf::RenderTarget* target);

    private:
        sf::Vector2f healthSize;
        sf::RectangleShape background;

        void initBackground();

}; 