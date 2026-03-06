#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Enemy{
    public:
        explicit Enemy(Player* player);
        virtual ~Enemy() = default;

        void update();
        void render(sf::RenderTarget* target);

        virtual void updateAppearance() = 0;

        void getDamaged(float damage); 

        virtual void initliazeHitbox() = 0;
    
        sf::Rect<float> returnBounds();

        float returnAttackTime();
        void restartAttackTime();

        float returnIframeTime();
        void restartIframeTime();

        bool isDead();
        //getter
        float getXpValue() const { return dropableXp; }

    protected:
        // Player pointer
        Player* playerPointer;
        
        // Variables
        float enemySpeed;
        float enemyHealth;
        float dropableXp;
        sf::Vector2f enemySize;
        sf::Vector2f enemyInitPosition;
        sf::Vector2f hitboxSize;

        // Texture 
        sf::Texture texture;
        sf::Sprite sprite;

        // Hitbox
        sf::RectangleShape hitBox;

        // Clock
        sf::Clock attackClock;
        sf::Clock iFrameClock;

        // Helper Functions
        sf::Vector2f decidedirection();
        void advanceposition();

};