#include "Enemy_Troll.h"
#include <iostream>

Enemy_Troll::Enemy_Troll(Player *player): Enemy(player)
{
    if (!texture.loadFromFile("../assets/troll.png"))
    {
        std::cout << "FAILED TO LOAD undead.png\n";
    }
    
    enemySpeed = GameConstants::TROLL_SPEED;
    enemyHealth = GameConstants::TROLL_HEALTH;
    dropableXp = GameConstants::TROLL_XP;

    initliazeHitbox();
    updateAppearance();
}

void Enemy_Troll::updateAppearance()
{
    sprite.setTexture(texture, true);

    sf::Vector2u textureSize = texture.getSize();

    
    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::ENEMYSIZE / textureSize.x,
            GameConstants::ENEMYSIZE / textureSize.y}
        );
    }
    
    sprite.setPosition(hitBox.getPosition());
}

void Enemy_Troll::initliazeHitbox()
{
    hitboxSize = enemySize;
    hitBox.setSize(enemySize);
    hitBox.setFillColor(sf::Color::Red);
    hitBox.setPosition(enemyInitPosition);
    hitBox.setOutlineColor(sf::Color::White);
    hitBox.setOutlineThickness(2.0f);
}