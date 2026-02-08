#include "Game.h"
#include "Enemy.h"
#include "Constants.h"
#include "Player.h"
#include "Enemy_Troll.h"
#include <iostream>

Game::Game(){
    initVariables();
    initWindow();
    initEnemies();
}

Game::~Game(){
    delete window;
    
    for (auto* e: enemies){
        delete e;
    }
    delete player;
    enemies.clear();
}

// Functions

// The games key press events
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
    
    for (auto* e : enemies){
        e->update();
        sf::Rect<float> playerBounds = player->returnBounds();
        sf::Rect<float> enemyBounds = e->returnBounds();

        if (playerBounds.findIntersection(enemyBounds) &&
            e->returnAttackTime() > GameConstants::ENEMY_HIT_FRAME){
            player->getDamaged(GameConstants::ENEMY_DAMAGE);
            
            std::cout << player->returnHealth() << std::endl;

            e->restartAttackTime();
            if (player->returnHealth() <= 0){
                window->close();
            }
        }
    }
    
    player->update();
}

void Game::render()
{   
    window->clear(sf::Color::Black);
    
    for (auto* e : enemies){
        e->render(window);
    }

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

void Game::initEnemies()
{
    Enemy* enemy = new Enemy_Troll(player);
    enemies.push_back(enemy);    
}

void Game::initWindow()
{
    window = new sf::RenderWindow(videoMode, "Dark lords", sf::Style::Default);

    // window.setVerticalSyncEnabled(true); it enables the fps to be the same as the refreshing rate of the monitor

    window->setFramerateLimit(60);
}
