#include "Game.h"
#include "Constants.h"
#include "Player.h"

// Constructors
Game::Game(){
    initVariables();
    initWindow();
}

Game::~Game(){
    delete window;
}

// Functions

void Game::pollevents()
{
    while (const std::optional event = window->pollEvent()){
        if (event->is<sf::Event::Closed>()){
            window->close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                window->close();
            }
        }
    }
}

void Game::update()
{
    pollevents();
    player->update();
}

void Game::render()
{
    window->clear(sf::Color::Black);
    player->render(window);
    window->display();
}

// Getters

bool Game::windowIsOpen() const
{   
    return window->isOpen();
}

// Private Functions

void Game::initVariables()
{    
    window = nullptr;
    player = new Player();
    videoMode.size.x = GameConstants::HEIGHT;
    videoMode.size.y = GameConstants::WIDTH;

}

void Game::initWindow()
{
    window = new sf::RenderWindow(videoMode, "Dark lords", sf::Style::Default);

    // window.setVerticalSyncEnabled(true); it enables the fps to be the same as the refreshing rate of the monitor

    window->setFramerateLimit(60);
}
