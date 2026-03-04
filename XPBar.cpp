#include "XPBar.h"
#include "Player.h"
#include "Constants.h"
#include <iostream>

XPBar::XPBar(float xp, Player* player){
    playerPointer = player;

    height = GameConstants::HEIGHT;
    width = GameConstants::WIDTH;
    xpBarSize.x = height / 2.f;
    xpBarSize.y = width / 20.f;

    if (!font.openFromFile("../assets/MinimalPixelFont.TTF")) {
        std::cerr << "Can't find the font file MinimalPixelFont.TTF\n";
    }

    this->setFillColor(sf::Color({0, 100, 0}));
    this->setSize({xpBarSize.x, xpBarSize.y});
    this->setOutlineColor({110, 14, 8});
    this->setOutlineThickness(3.f);
    this->setOrigin(sf::Vector2f(0, xpBarSize.y / 2.f));
    this->setPosition(sf::Vector2f(playerPointer->returnPosition().x - xpBarSize.x/2,
                                   playerPointer->returnPosition().y + 250));
    initBackground(xp);
    initLevelUp();
    showLevelUpMessage();
}

XPBar::~XPBar()
{
}

void XPBar::updateXp(float fraction)
{
    background.setSize({fraction * xpBarSize.x, xpBarSize.y});
}

void XPBar::update()
{
    sf::Vector2f playerPos = playerPointer->returnPosition();
    this->setPosition(sf::Vector2f(playerPos.x - xpBarSize.x/2, playerPos.y + 250));
    background.setPosition(this->getPosition());

    if (showMessage && messageTimer.getElapsedTime().asSeconds() > MESSAGE_DURATION) {
        showMessage = false;
    }
}

void XPBar::render(sf::RenderTarget *target)
{
    target->draw(*this);
    target->draw(background);

    if (showMessage) {
        sf::Vector2f playerPos = playerPointer->returnPosition();
        sf::FloatRect textBounds = levelUpText->getLocalBounds();
        levelUpText->setPosition(sf::Vector2f(playerPos.x - textBounds.size.x - 20.f, 20.f));
        target->draw(*levelUpText);
}
}

void XPBar::initBackground(float xp)

{
    background.setFillColor(sf::Color::Green);
    background.setSize({0, xpBarSize.y});
    background.setOrigin(sf::Vector2f(0, xpBarSize.y / 2.f));
    background.setPosition(this->getPosition());
    
}
void XPBar::initLevelUp()
{
    levelUpText = std::make_unique<sf::Text>(
        font, "LEVEL UP!!", 24);
    levelUpText->setFillColor(sf::Color::Yellow);
    levelUpText->setOutlineColor(sf::Color::Black);
    levelUpText->setOutlineThickness(2.f);
    showMessage = false;
    
}

void XPBar::showLevelUpMessage(){

    showMessage = true;
    messageTimer.restart();
}

