#include "Game.h"
#include "Enemy_Folder/Enemy.h"
#include "Constants.h"
#include "Player.h"
#include "Enemy_Folder/Enemy_Troll.h"
#include "Enemy_Folder/Enemy_Humongous.h"
#include "Enemy_Folder/Enemy_Goblin.h"
#include "Cards_Folder/Card.h"
#include "Cards_Folder/Health_Card.h"
#include "Cards_Folder/Damage_Card.h"
#include "Cards_Folder/Speed_Card.h"
#include "Map.h"
#include "Weapon.h"
#include "Menu_Folder/Settings.h"
#include <iostream>
#include <algorithm>

Game::Game(Settings* settings){
    settingsPointer = settings;
    initVariables();
    initWindow();
    initView();
    initMap();
    initCards();
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
            lastKeyPressed = keyPressed->scancode;

            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                if (gameState == GameState::Playing){
                    window->close();
                }else if (gameState == GameState::LevelUp){
                    gameState = GameState::Playing;
                    window->close();
                }
            }
        }
    }
}

void Game::update()
{
    pollevents();

    if (gameState == GameState::Playing){
        updatePlaying();
    }else if(gameState == GameState::LevelUp){
        updateLevelUp();
    }
}

void Game::render()
{   
    window->clear(sf::Color::Black);
    if (gameState == GameState::Playing){
        worldMap->render(window);

        for (auto* e : enemies){
            e->render(window);
        }

        player->render(window);
    }else if(gameState == GameState::LevelUp){
        window->setView(window->getDefaultView());
        for (auto* card : currentCards){
            card->render(window);
        }
    }
    
    window->display();
}

void Game::updatePlaying()
{
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

    enemyCollision();

    if (enemySpawnerTime.getElapsedTime().asSeconds() > GameConstants::ENEMY_SPAWN_TIME){
        enemyAutomaticSpawn();
        
        enemySpawnerTime.restart();
    }

    view.setCenter(player->returnPosition());

    window->setView(view);

    player->update();
    if (player->didLevelUp()){
        get3Cards();
        positionCards();
        gameState = GameState::LevelUp;
    }

}

void Game::updateLevelUp()
{
    bool cardChosen = false;

    if (lastKeyPressed == sf::Keyboard::Scancode::Num1){
        currentCards[0]->apply(*player);
        cardChosen = true;
    }else if(lastKeyPressed == sf::Keyboard::Scancode::Num2){
        currentCards[1]->apply(*player);
        cardChosen = true;
    }else if(lastKeyPressed == sf::Keyboard::Scancode::Num3){
        currentCards[2]->apply(*player);
        cardChosen = true;
    }

    if (cardChosen){
        currentCards.clear();
        lastKeyPressed = sf::Keyboard::Scancode::Unknown;
        gameState = GameState::Playing;
    }
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

// enemy collision with enemy
void Game::enemyCollision() {

    // Loop through all pairs of enemies
    for (size_t i = 0; i < enemies.size(); ++i) {
        for (size_t j = i + 1; j < enemies.size(); ++j) {

            // get the bounds of the two enemies
            sf::FloatRect boundsA = enemies[i]->returnBounds();
            sf::FloatRect boundsB = enemies[j]->returnBounds();

            // check for intersection
            if (auto intersectionOpt = boundsA.findIntersection(boundsB)) {

                //calculate the intersection rectangle
                sf::FloatRect intersection = *intersectionOpt;
                // how to push them apart
                sf::Vector2f push(0.f, 0.f);

                if (intersection.size.x < intersection.size.y) {

                    // horizontal push
                    if (boundsA.position.x < boundsB.position.x)

                        push.x = intersection.size.x;

                    else
                        push.x = -intersection.size.x;
                    }

                    // vertical push
                else {
                    if (boundsA.position.y < boundsB.position.y)

                        push.y = intersection.size.y;
                    
                    else
                        push.y = -intersection.size.y;
                    }
                
                // Move the enemies apart
                enemies[i]->move(-push * 0.5f);
                enemies[j]->move(push * 0.5f);

            }
        
        }
    }

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

void Game::initCards()
{
    cardPool.push_back(std::make_unique<Health_Card>());
    cardPool.push_back(std::make_unique<Damage_Card>());
    cardPool.push_back(std::make_unique<Speed_Card>());
}

void Game::get3Cards()
{
    currentCards.clear();

    std::uniform_int_distribution<> dist(0, cardPool.size() - 1);

    while (currentCards.size() < 3)
    {
        auto* candidate = cardPool[dist(gen)].get();

        auto it = std::find(currentCards.begin(), currentCards.end(), candidate);
        
        if (it == currentCards.end()){
            currentCards.push_back(candidate);
        }
    }
    
}

void Game::positionCards()
{
    int spacing = videoMode.size.x / 4.f;
    sf::Vector2f screenCenter = {videoMode.size.x / 2.f, videoMode.size.y / 2.f};

    for (int i = 0; i < currentCards.size(); i++){
        float x = screenCenter.x + (i - 1) * spacing;
        float y = screenCenter.y;
        currentCards[i]->setPosition(sf::Vector2f(x, y));
    }
}
