#include "Enemy_Humongous.h"
#include <iostream>

Enemy_Humongous::Enemy_Humongous(Player *player): Enemy(player)
{
    if (!texture.loadFromFile("../assets/Humongous.png"))
    {
        std::cout << "FAILED TO LOAD undead.png\n";
    }
    
    enemySpeed = GameConstants::HUMONGOUS_SPEED;
    enemyHealth = GameConstants::HUMONGOUS_HEALTH;
    dropableXp = GameConstants::HUMONGOUS_XP;

    initliazeHitbox();
    updateAppearance();
}

void Enemy_Humongous::updateAppearance()
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

void Enemy_Humongous::initliazeHitbox()
{
    hitboxSize = enemySize;
    hitBox.setSize(enemySize);
    hitBox.setFillColor(sf::Color::Red);
    hitBox.setPosition(enemyInitPosition);
    hitBox.setOutlineColor(sf::Color::White);
    hitBox.setOutlineThickness(2.0f);
}

