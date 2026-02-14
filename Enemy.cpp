#include "Enemy.h"
#include "Player.h"
#include "Constants.h"
#include <cmath>

Enemy::Enemy(Player* player): enemySpeed(GameConstants::ENEMYSPEED),
enemyInitPosition(GameConstants::ENEMYINITPOSITION_X, GameConstants::ENEMYINITPOSITION_Y),
enemySize({GameConstants::ENEMYSIZE, GameConstants::ENEMYSIZE}), playerPointer(player), texture(), sprite(texture)
{
    initliazeHitbox();
}

void Enemy::update(){
    advanceposition();
}

void Enemy::render(sf::RenderTarget* target)
{
    target->draw(sprite);
}

sf::Rect<float> Enemy::returnBounds()
{
    return hitBox.getGlobalBounds();
}

float Enemy::returnAttackTime()
{
    return attackClock.getElapsedTime().asSeconds();
}

void Enemy::restartAttackTime()
{
    attackClock.restart();
}

sf::Vector2f Enemy::decidedirection()
{
    sf::Vector2f playerPosition = playerPointer->returnPosition();
    sf::Vector2f enemyPosition = hitBox.getPosition();
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
    sf::Vector2f enemyPosition = hitBox.getPosition();
    
    hitBox.move(direction * enemySpeed);
    sprite.setPosition(hitBox.getPosition());
}

void Enemy::initliazeHitbox(){
    hitBox.setSize(enemySize);
    hitBox.setFillColor(sf::Color::Red);
    hitBox.setPosition(enemyInitPosition);
    hitBox.setOutlineColor(sf::Color::White);
    hitBox.setOutlineThickness(2.0f);
}