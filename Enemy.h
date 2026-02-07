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

        void initliazeHitbox();
    
        sf::Rect<float> returnBounds();

        float returnAttackTime();
        void restartAttackTime();

    protected:
        // Player pointer
        Player* playerPointer;
        
        // Variables
        float enemySpeed;
        sf::Vector2f enemySize;
        sf::Vector2f enemyInitPosition;

        // Texture 
        sf::Texture texture;
        sf::Sprite sprite;

        // Hitbox
        sf::RectangleShape hitBox;

        // Clock
        sf::Clock attackClock;
        float hitFrame;

        // Helper Functions
        sf::Vector2f decidedirection();
        void advanceposition();

};