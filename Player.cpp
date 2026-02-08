#include "Player.h"
#include "Constants.h"
#include "HealthBar.h"

// Constructor
Player::Player()
{
    speed = GameConstants::SPEED;
    health = GameConstants::PLAYER_HEALT;
    initHealthBar();
    initShape();
}

Player::~Player()
{
    delete healthBar;
}

// draw the player shape
void Player::initShape()
{

    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(GameConstants::HEIGHT / 2, GameConstants::WIDTH / 2));
    shape.setOrigin({shape.getSize().x / 2.f, shape.getSize().y / 2.f});
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
    target->draw(this->shape);
    healthBar->render(target);
}

sf::Vector2f Player::returnPosition(){
    return shape.getPosition();
}

sf::Rect<float> Player::returnBounds()
{
    return shape.getGlobalBounds();
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
        shape.move(sf::Vector2f(0.f, -speed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    {
        shape.move(sf::Vector2f(0.f, speed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    {
        shape.move(sf::Vector2f(-speed, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    {
        shape.move(sf::Vector2f(speed, 0.f));
    }
}

void Player::getDamaged(float damage)
{
    health -= damage;
}
