#include "HealthBar.h"
#include "Constants.h"
#include "Player.h"

HealthBar::HealthBar(float health, Player* player){   
    playerPointer = player;
    healthSize.x = GameConstants::HEIGHT / 400.f;
    healthSize.y = GameConstants::WIDTH / 20.f;
    
    this->setFillColor(sf::Color::Red);
    this->setSize({health * healthSize.x, healthSize.y});
    this->setOutlineColor({110, 14, 8});
    this->setOutlineThickness(3.f);
    this->setOrigin(this->getGeometricCenter());
    this->setPosition({playerPointer->returnPosition().x , playerPointer->returnPosition().y + 200});
    initBackground();
}

HealthBar::~HealthBar()
{

}

void HealthBar::updateHealth(float health)
{
    this->setSize({health * healthSize.x, healthSize.y});

    if (this->getSize().x < 0.0f){
        this->setSize({0, 0});
    }

}

void HealthBar::update()
{
    this->setPosition({playerPointer->returnPosition().x , playerPointer->returnPosition().y + 200});
    background.setPosition(this->getPosition());
}

void HealthBar::render(sf::RenderTarget* target)
{
    target->draw(background);
    target->draw(*this);  
}

void HealthBar::initBackground()
{
    background.setFillColor({255, 0, 0, 128});
    background.setSize(this->getSize());
    background.setOrigin(this->getGeometricCenter());
    background.setPosition(this->getPosition());
}
