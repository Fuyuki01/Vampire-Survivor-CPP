#pragma once
#include <SFML/Graphics.hpp>

class Player;

class HealthBar: public sf::RectangleShape {
    public:
        HealthBar(float initialHealth, float maxHealth, Player* player);
        ~HealthBar();

        void updateHealth(float currentHealth);
        void setMaxHealth(float newMaxHealth);
        
        void update();
        void render(sf::RenderTarget* target);

    private:
        float maxHealth;
        sf::Vector2f healthSize;
        sf::RectangleShape background;

        Player* playerPointer;

        void initBackground();

}; 