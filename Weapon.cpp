#include "Weapon.h"
#include "Player.h"

Weapon::Weapon(Player *player, const float damage): texture(), sprite(texture), damage(damage){

}

void Weapon::update()
{

}

void Weapon::render(sf::RenderTarget* target)
{
    target->draw(sprite);
}

void Weapon::initliazeHitbox()
{
    hitBox.setSize({texture.getSize().x, texture.getSize().y});
    hitBox.setFillColor(sf::Color::Blue);
    hitBox.setPosition({playerPointer->returnPosition().x + 5, playerPointer->returnPosition().y + 5});
}
