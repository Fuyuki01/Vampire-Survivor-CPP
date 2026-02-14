#include "Sword.h"
#include <iostream>
#include "Constants.h"

Sword::Sword(Player *player, const float damage): Weapon(player, damage)
{
    if (!texture.loadFromFile("weapon_knight_sword.png")){
        std::cout << "FAILED TO LOAD undead.png\n";
    }

}

void Sword::updateAppearance()
{
    sprite.setTexture(texture, true);
    
    sf::Vector2u textureSize = texture.getSize();
    
    sprite.setOrigin({textureSize.x / 2.f, textureSize.y / 2.f});
    
    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::PLAYER_SIZE / textureSize.x,
            GameConstants::PLAYER_SIZE / textureSize.y}
        );
    }
    
    sprite.setPosition(hitBox.getPosition());
}
