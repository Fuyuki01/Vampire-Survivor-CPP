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

    updateAppearance();
}

void Enemy_Goblin::updateAppearance()
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
