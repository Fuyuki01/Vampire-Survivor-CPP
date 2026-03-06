#include "HealthBar.h"
#include "Constants.h"
#include "Player.h"

HealthBar::HealthBar(float initialHealth, float maxHealth, Player* player) :
    playerPointer(player), maxHealth(maxHealth) {

    healthSize.x = GameConstants::HEIGHT / 2.f;
    healthSize.y = GameConstants::WIDTH / 20.f;
    
    this->setFillColor(sf::Color::Red);
    this->setSize({(initialHealth / maxHealth) * healthSize.x, healthSize.y});
    this->setOutlineColor({110, 14, 8});
    this->setOutlineThickness(3.f);
    this->setOrigin(sf::Vector2f(0, healthSize.y / 2.f));

    sf::Vector2f playerPos = playerPointer->returnPosition();

    float xPos = playerPos.x - healthSize.x / 2.f;
    float yPos = playerPos.y + 200.f;

    this->setPosition(sf::Vector2f(xPos, yPos));
    initBackground();
}

HealthBar::~HealthBar()
{

}

void HealthBar::updateHealth(float currentHealth)
{
    float fraction = currentHealth / maxHealth;
    if (fraction > 1.0f) fraction = 1.0f;
    if (fraction < 0.0f) fraction = 0.0f;

    this->setSize({fraction * healthSize.x, healthSize.y});

}

void HealthBar::update()
{
    sf::Vector2f playerPos = playerPointer->returnPosition();
    float xPos = playerPos.x - healthSize.x / 2.f;
    float yPos = playerPos.y + 200.f;

    this->setPosition(sf::Vector2f(xPos, yPos));
    background.setPosition(sf::Vector2f(xPos, yPos));
}

void HealthBar::render(sf::RenderTarget* target)
{
    target->draw(background);
    target->draw(*this);  
}

void HealthBar::initBackground()
{
    background.setFillColor(sf::Color(255, 0, 0, 128));
    background.setSize(this->getSize());
    background.setOrigin(sf::Vector2f(0, healthSize.y / 2.f));
    sf::Vector2f playerPos = playerPointer->returnPosition();
    float xPos = playerPos.x - healthSize.x / 2.f;
    float yPos = playerPos.y + 200.f;
    background.setPosition(sf::Vector2f(xPos, yPos));
}

void HealthBar::setMaxHealth(float newMaxHealth)
{
    maxHealth = newMaxHealth;
}
