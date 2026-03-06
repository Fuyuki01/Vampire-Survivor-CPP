#include "Enemy_Goblin.h"
#include "Constants.h"
#include "Player.h"
#include <iostream>

Enemy_Goblin::Enemy_Goblin(Player* player): Enemy(player)
{
    if (!texture.loadFromFile("../assets/goblin_idle/goblin_idle_anim_f0.png"))
    {
        std::cout << "FAILED TO LOAD undead.png\n";
    }

    enemySpeed = GameConstants::GOBLIN_SPEED;
    enemyHealth = GameConstants::GOBLIN_HEALTH;
    dropableXp = GameConstants::GOBLIN_XP;

    initliazeHitbox();
    updateAppearance();
}

void Enemy_Goblin::updateAppearance()
{
   sprite.setTexture(texture, true);

    sf::Vector2u textureSize = texture.getSize();

    sf::Vector2f origin = {textureSize.x / 2.f, textureSize.y / 2.f};
    sprite.setOrigin(origin);

    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::ENEMYSIZE / textureSize.x,
            GameConstants::ENEMYSIZE / textureSize.y}
        );
    }
    
    sprite.setPosition(hitBox.getPosition());
}

void Enemy_Goblin::initliazeHitbox()
{
    hitboxSize = {GameConstants::GOBLIN_HITBOX_X, GameConstants::GOBLIN_HITBOX_Y};
    sf::Vector2f origin = {hitboxSize.x / 2.f, hitboxSize.y / 2.f};
    
    hitBox.setSize(hitboxSize);
    hitBox.setOrigin(origin);
    hitBox.setFillColor(sf::Color::Red);
    hitBox.setPosition(enemyInitPosition);
    hitBox.setOutlineColor(sf::Color::White);
    hitBox.setOutlineThickness(2.0f);
}
