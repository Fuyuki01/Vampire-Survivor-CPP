#include "SettingMenu.h"
#include "Constants.h"
#include "MainMenu.h"
#include "Settings.h"
#include <iostream>

SettingMenu::SettingMenu(Settings* settings, MainMenu* mainMenu)
{
    width = GameConstants::WIDTH;
    height = GameConstants::HEIGHT;

    mainMenuPointer = mainMenu;
    settingsPointer = settings;

    if (!font.openFromFile("../assets/MinimalPixelFont.TTF")){
        std::cerr << "Can't find the font file MinimalPixelFont.TTF\n";
    }

    initWindow();
    initMenuItems();

    updateSelectionVisual();
}

SettingMenu::~SettingMenu()
{
    delete window;
    
    window = nullptr;
}

void SettingMenu::initMenuItems()
{
    items.clear();
    items.emplace_back(sf::Text(font, "Volume: " + std::to_string(settingsPointer->musicVolume), 36));

    std::string musicStatusText = std::string("Music: ") + (settingsPointer->musicStatus ? "ON" : "OFF");

    items.emplace_back(sf::Text(font, musicStatusText, 36));

    std::string fullScreenStatusText = std::string("FullScreen: ") + (settingsPointer->fullscreen ? "ON" : "OFF");

    items.emplace_back(font, fullScreenStatusText, 36);
    
    items.emplace_back(sf::Text(font, "Return", 36));

    float startPosition = height / 2.f - (items.size() * 50.f) / 2.f;
    float y = startPosition;
    for (auto &item : items) {
        item.setPosition(sf::Vector2f(width / 2.f, y));
        item.setFillColor(sf::Color::White);
        y += 50.f;
    }
}

void SettingMenu::run()
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
                    
                    case sf::Keyboard::Scancode::A:
                    case sf::Keyboard::Scancode::Left:
                        if (selected == 0){
                            if (settingsPointer->musicVolume >= 1){
                                mainMenuPointer->updateSound(--settingsPointer->musicVolume, settingsPointer->musicStatus);
                                updateMenuItems();
                            }
                        }
                        break;

                    case sf::Keyboard::Scancode::D:
                    case sf::Keyboard::Scancode::Right:
                        if (selected == 0){
                            if (settingsPointer->musicVolume < 100){
                                mainMenuPointer->updateSound(++settingsPointer->musicVolume, settingsPointer->musicStatus);
                                updateMenuItems();
                            }
                        }
                        break;

                    case sf::Keyboard::Scancode::Enter:
                        // MUSIC ON / OFF
                        if (selected == 1){
                            settingsPointer->musicStatus = !settingsPointer->musicStatus;
                            mainMenuPointer->updateSound(settingsPointer->musicVolume, settingsPointer->musicStatus);
                            updateMenuItems();
                        }
                        
                        // Full Screen ON / OFF
                        if (selected == 2){
                            settingsPointer->fullscreen = !settingsPointer->fullscreen;
                            window->close();
                        }

                        // RETURN
                        if(selected == 3){
                            window->close();
                        }

                        break;
                    case sf::Keyboard::Scancode::Escape:
                        window->close();

                        break;

                    default:
                        break;
                }
            }
        }

        window->clear(sf::Color::Black);
        for (auto &item : items) window->draw(item);
        window->display();
    }
    
}

void SettingMenu::initWindow()
{
    if (settingsPointer->fullscreen){
        window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Settings", sf::State::Fullscreen);
    }else{
        window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(width, height)), "Settings");
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

void SettingMenu::updateSelectionVisual()
{
    size_t i = 0;
    for (auto &item : items) {
        if (i++ == (size_t)selected)
            item.setFillColor(sf::Color::Yellow);
        else
            item.setFillColor(sf::Color::White);
    }
}

void SettingMenu::updateMenuItems()
{
    items[0].setString("Volume: " + std::to_string(settingsPointer->musicVolume));

    std::string musicStatusText = std::string("Music: ") + (settingsPointer->musicStatus ? "ON" : "OFF");
    
    items[1].setString(musicStatusText);

    std::string fullScreenStatusText = std::string("FullScreen: ") + (settingsPointer->fullscreen ? "ON" : "OFF");

    items[2].setString(fullScreenStatusText);
}
