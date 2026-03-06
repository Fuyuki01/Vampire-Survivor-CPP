#include "Game.h"
#include "Enemy.h"
#include "Constants.h"
#include "Player.h"
#include "Enemy_Troll.h"
#include "Enemy_Humongous.h"
#include "Enemy_Goblin.h"
#include "Map.h"
#include "Weapon.h"
#include "Settings.h"
#include <iostream>

Game::Game(Settings* settings){
    settingsPointer = settings;
    initVariables();
    initWindow();
    initView();
    initMap();
    totalDeath = false;
}

Game::~Game(){
    delete window;
    
    for (auto* e: enemies){
        delete e;
    }
    enemies.clear();

    delete player;   
    delete worldMap;
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
    
    for (auto* enemy : enemies){
        enemy->update();
        sf::Rect<float> playerBounds = player->returnBounds();
        sf::Rect<float> enemyBounds = enemy->returnBounds();

        if (playerBounds.findIntersection(enemyBounds) &&
            enemy->returnAttackTime() > GameConstants::ENEMY_HIT_FRAME){
            player->getDamaged(GameConstants::ENEMY_DAMAGE);

            enemy->restartAttackTime();
            if (player->returnHealth() <= 0){
                totalDeath = true;
                window->close();
                return;
            }
        }
        const auto& weaponvector = player->getWeapons();
        for (const auto& weapon : weaponvector){
            if (weapon->isActive()){
                auto weaponboundaries = weapon->returnBounds();
                if (weaponboundaries.findIntersection(enemyBounds)){
                    enemy->getDamaged(weapon->returnDamage());
                }
            }
        }
        for (size_t i = 0; i < enemies.size(); ) {
        if (enemies[i]->isDead()) {
            player->addXP(enemies[i]->getXpValue());
            delete enemies[i];
                enemies.erase(enemies.begin() + i);
        } else {
                ++i;
            }
        }
    }

    if (enemySpawnerTime.getElapsedTime().asSeconds() > GameConstants::ENEMY_SPAWN_TIME){
        enemyAutomaticSpawn();
        
        enemySpawnerTime.restart();
    }

    view.setCenter(player->returnPosition());

    window->setView(view);

    player->update();
}

void Game::render()
{   
    window->clear(sf::Color::Black);

    worldMap->render(window);
    
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

void Game::enemyAutomaticSpawn()
{

    std::uniform_int_distribution<> dist(0, 2);
    Enemy* enemy = nullptr;
    
    switch (dist(gen))
    {
    case 0:
        enemy = new Enemy_Humongous(player);
        break;
    case 1:
        enemy = new Enemy_Troll(player);
        break;
    case 2:
        enemy = new Enemy_Goblin(player);
        break;
    default:
        break;
    }

    enemies.push_back(enemy);  
}

void Game::initVariables()
{    
    window = nullptr;
    player = new Player();
    videoMode.size.x = GameConstants::HEIGHT;
    videoMode.size.y = GameConstants::WIDTH;

    gen.seed(rd());
}

void Game::initWindow()
{
    if (settingsPointer->fullscreen){
        window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Dark lords", sf::State::Fullscreen);
    }else{
        window = new sf::RenderWindow(videoMode, "Dark lords", sf::Style::Default);
    }
    
    window->requestFocus();

    auto desktop = sf::VideoMode::getDesktopMode(); 
    auto windowSize = window->getSize();

    sf::Vector2i desktopSize(static_cast<int>(desktop.size.x), static_cast<int>(desktop.size.y));
    sf::Vector2i windowSizes(static_cast<int>(windowSize.x), static_cast<int>(windowSize.y));

    window->setPosition(sf::Vector2i(
    ((desktopSize.x - windowSizes.x) / 2),
    ((desktopSize.y - windowSizes.y) / 2)
    ));

    // window.setVerticalSyncEnabled(true); it enables the fps to be the same as the refreshing rate of the monitor

    window->setFramerateLimit(60);
    
}

void Game::initView()
{
    view = window->getDefaultView();

    window->setView(view);

}

void Game::initMap()
{
    worldMap = new Map();
}
