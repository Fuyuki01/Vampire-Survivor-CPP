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
        int getLevel() const { return level; }

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
        HealthBar* healthBar;
        void initliazeHealthBar();

        // XP
        int level;
        float xp;
        float maxXP;
        XPBar* xpBar;
        void initializeXpBar();
        void levelUp();

        // Attack
        float playerDamage;
        void attack();

        // Weapon
        std::vector<std::unique_ptr<Weapon>> weapons;
        void initWeapon();

};