#include "Card.h"

Card::Card(): texture(), sprite(texture)
{
    if (!font.openFromFile("../assets/MinimalPixelFont.TTF")){
        std::cerr << "Can't find the font file MinimalPixelFont.TTF\n";
    }
}

void Card::render(sf::RenderTarget *target)
{
    target->draw(sprite);
    
    for (auto& text : description) target->draw(text);
}

void Card::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
    
    sf::FloatRect bounds = sprite.getGlobalBounds();

    float offset = 50.f;
    float textY = position.y + bounds.size.y / 2.f + offset;

    for (int i = 0; i < description.size(); i++){
        description[i].setPosition(sf::Vector2f(position.x, textY));
        sf::FloatRect textBounds = description[i].getGlobalBounds();
        description[i].setOrigin(sf::Vector2f(textBounds.size.x / 2.f, textBounds.size.y / 2.f));
        description[i].setFillColor(sf::Color::White);
        textY += offset;
    }
}
