#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Weapon{
    public:
        explicit Weapon(Player* player, const float damage);
        ~Weapon() = default;

        virtual void updateAppearance() = 0;

        void update();
        void render(sf::RenderTarget* target);

    protected:
        // Damage
        float damage;

        // Texture
        sf::Texture texture;

        // Sprite
        sf::Sprite sprite;
        
        // Hitbox
        void initliazeHitbox();
        sf::RectangleShape hitBox;

        // Player
        Player* playerPointer;

};