#include "Speed_Card.h"

Speed_Card::Speed_Card(): Card()
{
    if (!texture.loadFromFile("../assets/Cards/Card2.png")){
        std::cout << "FAILED TO LOAD Card2.png\n";
    }
    increaOnSpeed = GameConstants::INCREASE_SPEED_CARD;

    initAppearance();
}

void Speed_Card::initAppearance()
{
    sprite.setTexture(texture, true);
    
    sf::Vector2u textureSize = texture.getSize();
    
    sprite.setOrigin({textureSize.x / 2.f, textureSize.y / 2.f});

    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {1,
            1}
        );
    }
}

void Speed_Card::apply(Player& player)
{
    player.updateSpeed(increaOnSpeed);
}
