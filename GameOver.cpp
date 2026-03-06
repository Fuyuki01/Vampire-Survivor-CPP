#include "GameOver.h"
#include "Constants.h"
#include "Settings.h"
#include <iostream>

GameOver::GameOver(Settings* settings)
{
    settingsPointer = settings;

    if (settingsPointer->fullscreen){
        width = sf::VideoMode::getDesktopMode().size.x;
        height = sf::VideoMode::getDesktopMode().size.y;
    }else{
        width = GameConstants::WIDTH;
        height = GameConstants::HEIGHT;
    }

    if (!font.openFromFile("../assets/MinimalPixelFont.TTF")) {
        std::cerr << "Can't find the font file MinimalPixelFont.TTF\n";
    }

    gameOverText = std::make_unique<sf::Text>(
        font, "GAME OVER", 72);
    gameOverText->setFillColor(sf::Color::Red);
    gameOverText->setStyle(sf::Text::Bold);

    sf::FloatRect textRect = gameOverText->getLocalBounds();
    gameOverText->setOrigin(sf::Vector2f(
        textRect.position.x + textRect.size.x / 2.0f,
        textRect.position.y + textRect.size.y / 2.0f ));
    gameOverText->setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));

    initwindow();

}

void GameOver::initwindow()
{
    if (settingsPointer->fullscreen){
        window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Game Over", sf::State::Fullscreen);
    }else{
        window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(width, height)), "Game Over");
    }
    
    window->setFramerateLimit(60);

    auto desktop = sf::VideoMode::getDesktopMode();
    auto windowSize = window->getSize();

    sf::Vector2i desktopSize(static_cast<int>(desktop.size.x), static_cast<int>(desktop.size.y));
    sf::Vector2i windowSizes(static_cast<int>(windowSize.x), static_cast<int>(windowSize.y));

    window->setPosition(sf::Vector2i(
    ((desktopSize.x - windowSizes.x) / 2),
    ((desktopSize.y - windowSizes.y) / 2)
    ));
}

bool GameOver::run()
{   
    sf::Clock clock;
    
    while (window->isOpen()) {
        while (auto event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
                break;
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {

                    case sf::Keyboard::Scancode::Escape:
                        window->close();
                        return true;

                    default:
                        break;
                }
            }
        }

        if (clock.getElapsedTime().asSeconds() >= 5.0f) {
            window->close();
            return true;
        }

        window->clear(sf::Color::Black);
        window->draw(*gameOverText);
        window->display();
    }
    
    return false;

}