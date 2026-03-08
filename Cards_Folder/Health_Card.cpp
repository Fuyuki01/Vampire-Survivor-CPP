#include "Health_Card.h"

Health_Card::Health_Card(): Card()
{
    if (!texture.loadFromFile("../assets/Cards/Card1.png")){
        std::cout << "FAILED TO LOAD Card1.png\n";
    }
    increaOnHealth = GameConstants::INCREASE_HEALTH_CARD;

    initAppearance();
    initText();
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

void Health_Card::initText()
{
    description.clear();
    
    description.push_back(sf::Text(font, "Health Card", 36));
    
    std::string healthText = std::string("+") + std::to_string(int(increaOnHealth)) + std::string(" base health");
    description.push_back(sf::Text(font, healthText, 36));
    
    std::string healthText2 = std::string("+ ") + std::to_string(int(increaOnHealth / 2.f)) + std::string(" Heal");
    description.push_back(sf::Text(font, healthText2, 36));
}

void Health_Card::apply(Player& player)
{
    player.updateHealth(increaOnHealth);
}
