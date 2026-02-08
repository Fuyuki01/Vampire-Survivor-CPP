#include "HealthBar.h"
#include "Constants.h"

HealthBar::HealthBar(float health)
{   
    healthSize.x = GameConstants::HEIGHT / 400.f;
    healthSize.y = GameConstants::WIDTH / 20.f;
    
    this->setFillColor(sf::Color::Red);
    this->setSize({health * healthSize.x, healthSize.y});
    this->setOutlineColor({110, 14, 8});
    this->setOutlineThickness(3.f);
    this->setOrigin(this->getGeometricCenter());
    this->setPosition({400, 500});
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
