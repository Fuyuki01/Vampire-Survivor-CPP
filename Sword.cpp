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

    sprite.setOrigin({textureSize.x / 2.f, static_cast<float>(textureSize.y)});

    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::SWORD_SIZE / textureSize.x,
            GameConstants::SWORD_SIZE / textureSize.y}
        );
    }

}

void Sword::updateAnimation(int index, int weaponCount)
{
    sf::Vector2f playerPosition = playerPointer->returnPosition();

    float swingRadius = 130;
    
    float radius = (GameConstants::PLAYER_SIZE / 2) + 40;

    float verticalOffset = 20;

    float progress = attackDuration.getElapsedTime().asSeconds() / durationTime;

    if (progress > 1) progress = 1;

    float angleStep = 360.f / weaponCount;
    float angle = index * angleStep;
    float angleRadians = angle * M_PI / 180;

    float start = angle - swingRadius;
    
    float end = angle + swingRadius;
    
    float anchorX = playerPosition.x + cos(angleRadians) * radius;
    float anchorY = playerPosition.y + sin(angleRadians) * radius;

    sf::Vector2f anchor = {anchorX, anchorY};

    swingAngle = sf::degrees(start + std::sin(progress * M_PI) * (end - start));

    sprite.setRotation(swingAngle + sf::degrees(90.f));
    sprite.setPosition(anchor);
    hitBox.setRotation(swingAngle + sf::degrees(90.f));
    hitBox.setPosition(anchor);
}

std::unique_ptr<Weapon> Sword::clone() const
{
    return std::make_unique<Sword>(*this);
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
