#include "MainMenu.h"
#include "Constants.h"
#include <iostream>

MainMenu::MainMenu()
{
    width = GameConstants::WIDTH;
    height = GameConstants::HEIGHT;

    if (!font.openFromFile("../assets/MinimalPixelFont.TTF")) {
        std::cerr << "Can't find the font file MinimalPixelFont.TTF\n";
    }

    if (!music.openFromFile("../assets/theme.wav")) {
        std::cerr << "Can't find the sound file theme.wav\n";
        return;
    }

    initMusic();
    
    // Initialize Window
    initwindow();
    
    initMenuItems();
    
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

void MainMenu::initwindow()
{

    window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(width, height)), "Main Menu");
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

void MainMenu::initMenuItems()
{
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
}

void MainMenu::initMusic()
{
    musicVolume = GameConstants::MUSIC_SOUND;
    music.setLooping(true);
    music.setVolume(musicVolume);
    music.play();
}

// Main loop for the main menu
int MainMenu::run()
{

    while (window->isOpen()) {
        while (auto event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
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
                    window->close();
                    if (selected == 0){
                        // Play
                        return 0;
                    }else if(selected == 1){
                        // Settings
                        return 1;
                    }else{
                        // Exit
                        return 2;
                    }

                case sf::Keyboard::Scancode::Escape:
                    window->close();
                    // Exit
                    return 2;

                default:
                    break;
                }
            }
        }

        window->clear(sf::Color::Black);
        for (auto &item : items) window->draw(item);
        window->display();
    }

    // Exit
    return 2;
}

void MainMenu::updateSound(int musicVolume, bool musicOn)
{
    if (musicOn){
        if (music.getStatus() != sf::Music::Status::Playing){
            music.play();
        }
        music.setVolume(musicVolume);
    }

    if (!musicOn){
        if (music.getStatus() == sf::Music::Status::Playing){
            music.stop(); 
        }
        
       music.setVolume(musicVolume);
    }

    
}

int MainMenu::returnVolume()
{
    return musicVolume;
}
