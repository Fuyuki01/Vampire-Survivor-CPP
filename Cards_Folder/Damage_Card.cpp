#include "Damage_Card.h"

Damage_Card::Damage_Card(): Card()
{
    if (!texture.loadFromFile("../assets/Cards/Card3.png")){
        std::cout << "FAILED TO LOAD Card3.png\n";
    }
    increaseOnDamage = GameConstants::INCREASE_DAMAGE_CARD;

    initAppearance();
    initText();
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

void Damage_Card::initText()
{
    description.clear();
    
    description.push_back(sf::Text(font, "Damage Card", 36));
    
    std::string damageText = std::string("+") + std::to_string(int(increaseOnDamage)) + std::string(" Damage");
    description.push_back(sf::Text(font, damageText, 36));
}

void Damage_Card::apply(Player& player)
{
    player.updateWeaponDamage(increaseOnDamage);
}
