#include "Enemy_Troll.h"
#include "Constants.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Enemy_Troll::Enemy_Troll(Player *player): Enemy(player)
{
    if (!texture.loadFromFile("troll.png"))
    {
        std::cout << "FAILED TO LOAD undead.png\n";
    }
    
    enemySpeed = GameConstants::UNDEAD_SPEED;

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
