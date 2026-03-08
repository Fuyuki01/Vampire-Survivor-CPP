#include "Health_Card.h"

Health_Card::Health_Card(): Card()
{
    if (!texture.loadFromFile("../assets/Cards/Card1.png")){
        std::cout << "FAILED TO LOAD Card1.png\n";
    }
    increaOnHealth = GameConstants::INCREASE_HEALTH_CARD;

    initAppearance();
}

void Health_Card::initAppearance()
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

void Health_Card::apply(Player& player)
{
    player.updateHealth(increaOnHealth);
}
