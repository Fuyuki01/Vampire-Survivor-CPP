#include "Weapons_Card.h"

Weapons_Card::Weapons_Card()
{
    if (!texture.loadFromFile("../assets/Cards/Card4.png")){
        std::cout << "FAILED TO LOAD Card2.png\n";
    }

    increaseOnWeapon = 1;
    
    initAppearance();
    initText();
}

void Weapons_Card::initAppearance()
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


void Weapons_Card::initText()
{
    description.clear();
    
    description.push_back(sf::Text(font, "Weapon Card", 36));
    
    std::string speedText = std::string("+") + std::to_string(int(increaseOnWeapon)) + std::string(" Weapon");
    description.push_back(sf::Text(font, speedText, 36));
}

void Weapons_Card::apply(Player& player)
{
    player.updateWeaponCount(increaseOnWeapon);
}
