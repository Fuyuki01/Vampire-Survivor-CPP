#include "Damage_Card.h"

Damage_Card::Damage_Card(): Card()
{
    if (!texture.loadFromFile("../assets/Cards/Card3.png")){
        std::cout << "FAILED TO LOAD Card3.png\n";
    }
    increaseOnDamage = GameConstants::INCREASE_DAMAGE_CARD;

    initAppearance();
}

void Damage_Card::initAppearance()
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

void Damage_Card::apply(Player& player)
{
    player.updateWeaponDamage(increaseOnDamage);
}
