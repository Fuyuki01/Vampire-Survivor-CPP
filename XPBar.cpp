#include "XPBar.h"
#include "Player.h"
#include "Constants.h"

XPBar::XPBar(float xp, Player* player){
    playerPointer = player;
    xpBarSize.x = GameConstants::HEIGHT / 400.f;
    xpBarSize.y = GameConstants::WIDTH / 20.f;

    this->setFillColor(sf::Color(0, 100, 0));
    this->setSize({xpBarSize.x, xpBarSize.y});
    this->setOutlineColor({110, 14, 8});
    this->setOutlineThickness(3.f);
    this->setOrigin(this->getGeometricCenter());
    this->setPosition({playerPointer->returnPosition().x, playerPointer->returnPosition().y + 250});
    initBackground(xp);
}

XPBar::~XPBar()
{

}

void XPBar::updateXp(float xp)
{
    background.setSize({xp * xpBarSize.x, xpBarSize.y});
}

void XPBar::update()
{
    this->setPosition({playerPointer->returnPosition().x, playerPointer->returnPosition().y + 250});
    background.setPosition(this->getPosition());
}

void XPBar::render(sf::RenderTarget *target)
{
    target->draw(background);
    target->draw(*this);
}

void XPBar::initBackground(float xp)
{
    background.setFillColor(sf::Color::Green);
    background.setSize({xp * xpBarSize.x, xpBarSize.y});
    background.setOrigin(this->getGeometricCenter());
    background.setPosition(this->getPosition());
}
