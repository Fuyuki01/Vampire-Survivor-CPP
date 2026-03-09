#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Weapon{
    public:
        Weapon(Player* player, const float damage);
        virtual ~Weapon() = default;

        virtual void updateAppearance() = 0;

        virtual void update(int index, int weaponsSize);
        virtual void render(sf::RenderTarget* target);

        virtual int returnDamage() = 0;
        void updateDamage(float addWeaponDamage);

        sf::Rect<float> returnBounds();
        bool isActive() const;

        // Clone
        virtual std::unique_ptr<Weapon> clone() const = 0;
        
    protected:
        // Damage
        float damage;

        // Texture
        sf::Texture texture;

        // Sprite
        sf::Sprite sprite;

        // Animation
        virtual void updateAnimation(int index, int weaponCount) = 0;
        
        // Hitbox
        virtual void initializeHitbox() = 0;
        sf::RectangleShape hitBox;

        // Player
        Player* playerPointer;

        // Attack timer
        sf::Clock cooldown;
        sf::Clock attackDuration;
        sf::Clock attackAnimation;
        float attackAnimationTime;
        float cooldownTime;
        float durationTime;
        bool active;

        virtual void attack() = 0;
};