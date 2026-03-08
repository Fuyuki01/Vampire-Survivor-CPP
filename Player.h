#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class HealthBar;
class XPBar;
class Weapon;

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
        const std::vector<std::unique_ptr<Weapon>>& getWeapons() const;
        bool returnFacingRight();
        void addXP(float amount);
        int getLevel() const; 
        void updateHealth(float addHealth);
        void updateSpeed(float addSpeed);
        void updateWeaponDamage(float addWeaponDamage);
        bool didLevelUp();

    private:
        // Texture
        sf::Texture texture;

        // Sprite
        sf::Sprite sprite;
        void updateAppearance();
        bool facingRight = true;

        // Hitbox
        void initliazeHitbox();
        sf::RectangleShape hitBox;

        // Speed
        float speed;

        // Health
        float health;
        float maxHealth;
        HealthBar* healthBar;
        void initliazeHealthBar();

        // XP
        int level;
        float xp;
        float maxXP;
        XPBar* xpBar;
        bool levelUped;
        void initializeXpBar();
        void levelUp();

        // Weapon
        std::vector<std::unique_ptr<Weapon>> weapons;
        void initWeapon();

};