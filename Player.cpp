#include "Player.h"
#include "Constants.h"

// Constructor
Player::Player()
{
    speed = GameConstants::SPEED;
    initShape();
}


// draw the player shape
void Player::initShape()
{

    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(GameConstants::HEIGHT / 2, GameConstants::WIDTH / 2));
}

void Player::update()
{
    keyInputs();
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}

sf::Vector2f Player::returnPosition(){
    return shape.getPosition();
}

sf::Rect<float> Player::returnBounds()
{
    return shape.getGlobalBounds();
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