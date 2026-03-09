#include "Sword.h"
#include "Constants.h"
#include "Player.h"
#include <cmath>
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

    sprite.setOrigin({textureSize.x / 2.f, static_cast<float>(textureSize.y)});

    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::SWORD_SIZE / textureSize.x,
            GameConstants::SWORD_SIZE / textureSize.y}
        );
    }

}

void Sword::updateAnimation()
{
    sf::Vector2f playerPosition = playerPointer->returnPosition();
    sf::Vector2f anchorPosition;
    
    float horizontalOffset = (GameConstants::PLAYER_SIZE / 2) + 40;

    float verticalOffset = 20;

    float progress = attackDuration.getElapsedTime().asSeconds() / durationTime;

    if (progress > 1) progress = 1;

    float start = playerPointer->returnFacingRight() ? -20 : 20;
    
    float end = playerPointer->returnFacingRight() ? 150 : -150;

    if(playerPointer->returnFacingRight()){
        anchorPosition = {playerPosition.x + horizontalOffset, playerPosition.y + verticalOffset};

    }else{
        anchorPosition = {playerPosition.x - horizontalOffset, playerPosition.y + verticalOffset};      

    }

    swingAngle = sf::degrees(start + std::sin(progress * M_PI) * (end - start));

    sprite.setRotation(swingAngle);
    sprite.setPosition(anchorPosition);
    hitBox.setRotation(swingAngle);
    hitBox.setPosition(anchorPosition);
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

    float horizontalOffset = GameConstants::PLAYER_SIZE / 2;

    if(playerPointer->returnFacingRight()){
        sf::Vector2f hitBoxPosition = {playerPosition.x + horizontalOffset, playerPosition.y};
        return hitBoxPosition;
    }else{
        sf::Vector2f hitBoxPosition = {playerPosition.x - horizontalOffset, playerPosition.y};
        return hitBoxPosition;
    }
}

void Sword::initializeHitbox()
{
    sf::Vector2u size = texture.getSize();

    sf::Vector2f textureSize = {
        static_cast<float>(size.x), static_cast<float>(size.y)
    };

    hitBox.setOrigin({textureSize.x / 2.f, textureSize.y});

    if (textureSize.x > 0 && textureSize.y > 0) {
        hitBox.setScale(
            {GameConstants::SWORD_SIZE / textureSize.x,
            GameConstants::SWORD_SIZE / textureSize.y}
        );
    }

    hitBox.setSize(textureSize);
    hitBox.setFillColor(sf::Color::Blue);
}
