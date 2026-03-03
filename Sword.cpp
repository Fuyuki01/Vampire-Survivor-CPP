#include "Sword.h"
#include "Constants.h"
#include "Player.h"
#include <iostream>

Sword::Sword(Player *player, const float damage): Weapon(player, damage)
{
    if (!texture.loadFromFile("../assets/weapon_knight_sword.png")){
        std::cout << "FAILED TO LOAD undead.png\n";
    }
    initializeHitbox();
    updateAppearance();
}

int Sword::returnDamage()
{
    return damage;
}

void Sword::updateAppearance()
{
    sprite.setTexture(texture, true);
    
    sf::Vector2u textureSize = texture.getSize();
    
    sprite.setOrigin({textureSize.x / 2.f, textureSize.y / 2.f});
    
    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::SWORD_SIZE / textureSize.x,
            GameConstants::SWORD_SIZE / textureSize.y}
        );
    }
    
    sprite.setPosition(hitBox.getPosition());
}

void Sword::attack()
{
    sf::Vector2f hitBoxPosition = decideAttackPosition();

    hitBox.setPosition(hitBoxPosition);
    sprite.setPosition(hitBoxPosition);

}

sf::Vector2f Sword::decideAttackPosition()
{
    sf::Vector2f playerPosition = playerPointer->returnPosition();

    if(playerPointer->returnFacingRight()){
        sf::Vector2f hitBoxPosition = {playerPosition.x + 10, playerPosition.y};
        return hitBoxPosition;
    }else{
        sf::Vector2f hitBoxPosition = {playerPosition.x - 10, playerPosition.y};
        return hitBoxPosition;
    }
}

void Sword::initializeHitbox()
{
    sf::Vector2u size = texture.getSize();
    sf::Vector2f textureSize = {
        static_cast<float>(size.x), static_cast<float>(size.y)
    };
    hitBox.setSize(textureSize);
    hitBox.setFillColor(sf::Color::Blue);
    hitBox.setPosition({playerPointer->returnPosition().x + 5, playerPointer->returnPosition().y + 5});
}
