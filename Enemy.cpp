#include "Enemy.h"
#include "Constants.h"

Enemy::Enemy(): enemySpeed(GameConstants::ENEMYSPEED), 
enemyPosition(GameConstants::ENEMYPOSITION_X, GameConstants::ENEMYPOSITION_Y),
enemySize(GameConstants::ENEMYSIZE, GameConstants::ENEMYSIZE)
{

    updateAppearance();

}

void Enemy::updateAppearance(){
    rectangle.setSize(enemySize);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(enemyPosition);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(2.0f);
}