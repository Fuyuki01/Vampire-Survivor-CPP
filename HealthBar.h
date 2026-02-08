#pragma once
#include <SFML/Graphics.hpp>

class Player;

class HealthBar: public sf::RectangleShape {
    public:
        HealthBar(float health, Player* player);
        ~HealthBar();

        void updateHealth(float health);
        void update();
        void render(sf::RenderTarget* target);

    private:
        sf::Vector2f healthSize;
        sf::RectangleShape background;

        Player* playerPointer;

        void initBackground();

}; 