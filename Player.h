#pragma once
#include <SFML/Graphics.hpp>

class HealthBar;
class Sword;

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
        // Texture
        sf::Texture texture;

        // Sprite
        sf::Sprite sprite;
        void updateAppearance();

        // Hitbox
        void initliazeHitbox();
        sf::RectangleShape hitBox;

        // Speed
        float speed;

        // Health
        float health;
        HealthBar* healthBar;
        void initliazeHealthBar();

        // Attack
        float playerDamage;
        void attack();

        // Weapon
        Sword* basicSword;
};