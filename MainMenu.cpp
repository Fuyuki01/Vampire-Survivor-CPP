#include "MainMenu.h"
#include "Constants.h"
#include <iostream>

MainMenu::MainMenu()
{
    width = GameConstants::WIDTH;
    height = GameConstants::HEIGHT;

    if (!font.openFromFile("MinimalPixelFont.TTF")) {
        std::cout << "Can't find the font file MinimalPixelFont.TTF\n";
    }

    // Initialize menu items
    items.clear();
    items.emplace_back(sf::Text(font, "Play", 36));
    items.emplace_back(sf::Text(font, "Settings", 36));
    items.emplace_back(sf::Text(font, "Exit", 36));

    // Position menu items
    float startPosition = height / 2.f - (items.size() * 50.f) / 2.f;
    float y = startPosition;
    for (auto &item : items) {
        item.setPosition(sf::Vector2f(width / 2.f, y));
        item.setFillColor(sf::Color::White);
        y += 50.f;
    }
    updateSelectionVisual();
}

// Selected menu highlight
void MainMenu::updateSelectionVisual()
{
    size_t i = 0;
    for (auto &item : items) {
        if (i++ == (size_t)selected)
            item.setFillColor(sf::Color::Yellow);
        else
            item.setFillColor(sf::Color::White);
    }
}

// Main loop for the main menu
bool MainMenu::run()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(width, height)), "Main Menu");
    window.setFramerateLimit(60);

        while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                break;
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                case sf::Keyboard::Scancode::S:
                case sf::Keyboard::Scancode::Down:
                    if (selected < items.size() - 1) selected++;
                    updateSelectionVisual();
                    break;

                case sf::Keyboard::Scancode::W:
                case sf::Keyboard::Scancode::Up:
                    if (selected > 0) selected--;
                    updateSelectionVisual();
                    break;

                case sf::Keyboard::Scancode::Enter:
                    window.close();
                    return selected == 0;

                case sf::Keyboard::Scancode::Escape:
                    window.close();
                    return false;

                default:
                    break;
                }
            }
        }

        window.clear(sf::Color::Black);
        for (auto &item : items) window.draw(item);
        window.display();
    }

    return false;
}