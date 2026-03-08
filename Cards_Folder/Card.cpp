#include "Card.h"

Card::Card(): texture(), sprite(texture)
{
    
}

void Card::render(sf::RenderTarget *target)
{
    target->draw(sprite);
}

void Card::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}
