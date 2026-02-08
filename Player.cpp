#include "Player.h"
#include "Constants.h"
#include "HealthBar.h"
#include <iostream>

// Constructor
Player::Player(): texture(), sprite(texture)
{
    if (!texture.loadFromFile("knight_f_idle_anim_f0.png")){
        std::cout << "FAILED TO LOAD undead.png\n";
    }
    
    speed = GameConstants::SPEED;
    health = GameConstants::PLAYER_HEALT;
    
    initHealthBar();
    initliazeHitbox();
    updateAppearance();
}

Player::~Player()
{
    delete healthBar;
}

void Player::updateAppearance(){
    sprite.setTexture(texture, true);

    sf::Vector2u textureSize = texture.getSize();
    
    sprite.setOrigin({textureSize.x / 2.f, textureSize.y / 2.f});
    
    if (textureSize.x > 0 && textureSize.y > 0) {
        sprite.setScale(
            {GameConstants::PLAYER_SIZE / textureSize.x,
            GameConstants::PLAYER_SIZE / textureSize.y}
        );
    }
    
    sprite.setPosition(hitBox.getPosition());
}

// draw the player shape
void Player::initliazeHitbox()
{
    hitBox.setSize({GameConstants::PLAYER_SIZE, GameConstants::PLAYER_SIZE});
    hitBox.setFillColor(sf::Color::Green);
    hitBox.setPosition(sf::Vector2f(GameConstants::HEIGHT / 2, GameConstants::WIDTH / 2));
    hitBox.setOrigin({hitBox.getSize().x / 2.f, hitBox.getSize().y / 2.f});
}

void Player::initHealthBar()
{
    healthBar = new HealthBar(health, this);
}

void Player::update()
{
    if (health > 0){  
        keyInputs();
        healthBar->updateHealth(health);
        healthBar->update();
    }
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(sprite);
    healthBar->render(target);
}

sf::Vector2f Player::returnPosition(){
    return hitBox.getPosition();
}

sf::Rect<float> Player::returnBounds()
{
    return hitBox.getGlobalBounds();
}

float Player::returnHealth()
{
    return health;
}


void Player::keyInputs()
{
    // Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
        hitBox.move(sf::Vector2f(0.f, -speed));
        sprite.setPosition(hitBox.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    {
        hitBox.move(sf::Vector2f(0.f, speed));
        sprite.setPosition(hitBox.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    {
        hitBox.move(sf::Vector2f(-speed, 0.f));
        sprite.setPosition(hitBox.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    {
        hitBox.move(sf::Vector2f(speed, 0.f));
        sprite.setPosition(hitBox.getPosition());
    }
}

void Player::getDamaged(float damage)
{
    health -= damage;
}
