#include "Enemy.h"
#include "Player.h"
#include "Constants.h"

Enemy::Enemy(Player* player): enemySpeed(GameConstants::ENEMYSPEED), 
enemyInitPosition(GameConstants::ENEMYINITPOSITION_X, GameConstants::ENEMYINITPOSITION_Y),
enemySize(GameConstants::ENEMYSIZE, GameConstants::ENEMYSIZE), playerPointer(player)
{

    updateAppearance();

}

void Enemy::update(){
    decidedirection();
    advanceposition();
}

void Enemy::render()
{
}

sf::Vector2f Enemy::decidedirection()
{
    sf::Vector2f playerPosition = playerPointer->returnPosition();
    sf::Vector2f enemyPosition = rectangle.getPosition();
    sf::Vector2f direction = playerPosition - enemyPosition;
    return direction;

}

void Enemy::advanceposition()
{
    sf::Vector2f direction = decidedirection();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f){
        direction /= length;
    }
    sf::Vector2f enemyPosition = rectangle.getPosition();
    
    rectangle.move(direction * enemySpeed);
}

void Enemy::updateAppearance(){
    rectangle.setSize(enemySize);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(enemyInitPosition);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(2.0f);
}