#include "Player.h"
#include "Constants.h"
#include "HealthBar.h"
#include "XPBar.h"
#include "Sword.h"
#include <iostream>

// Constructor
Player::Player(): texture(), sprite(texture) , xp(0) , maxXP(100.0f) , level(0) , knockbackVelocity(0.f, 0.f)
{
    if (!texture.loadFromFile("../assets/knight_f_idle_anim_f0.png")){
        std::cout << "FAILED TO LOAD undead.png\n";
    }
    
    speed = GameConstants::SPEED;
    health = GameConstants::PLAYER_HEALTH;
    maxHealth = GameConstants::PLAYER_HEALTH;
    levelUped = false;

    initliazeHealthBar();
    initliazeHitbox();
    initializeXpBar();
    initWeapon();
    updateAppearance();
}

Player::~Player()
{
    delete healthBar;
    delete xpBar;
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

bool Player::returnFacingRight()
{
    return facingRight;
}

// draw the player shape
void Player::initliazeHitbox()
{
    hitBox.setSize({GameConstants::PLAYER_SIZE, GameConstants::PLAYER_SIZE});
    hitBox.setFillColor(sf::Color::Green);
    hitBox.setPosition(sf::Vector2f(GameConstants::HEIGHT / 2, GameConstants::WIDTH / 2));
    hitBox.setOrigin({hitBox.getSize().x / 2.f, hitBox.getSize().y / 2.f});
}

void Player::initliazeHealthBar()
{
    healthBar = new HealthBar(health, maxHealth, this);
}

void Player::initializeXpBar()
{
    xpBar = new XPBar(xp, this);
}

void Player::initWeapon()
{
    weapons.push_back(std::make_unique<Sword>(this, GameConstants::BASIC_SWORD_DAMAGE));
}

const std::vector<std::unique_ptr<Weapon>>& Player::getWeapons() const
{
    return weapons;
}

void Player::update()
{
    if (health > 0){  
        keyInputs();

        // apply knockback velocity
        hitBox.move(knockbackVelocity);
        sprite.setPosition(hitBox.getPosition());

        // decay knockback velocity
        knockbackVelocity *= GameConstants::KNOCKBACK_DECAY;

        // if the velocity is very small, set it to zero
        if (std::abs(knockbackVelocity.x) < 0.1f) knockbackVelocity.x = 0.f;
        if (std::abs(knockbackVelocity.y) < 0.1f) knockbackVelocity.y = 0.f;

        healthBar->updateHealth(health);
        healthBar->update();
        float xpFraction = xp / maxXP;
        if (xpFraction > 1.0f) xpFraction = 1.0f;
        xpBar->updateXp(xpFraction);
        xpBar->update();

        for (auto& weapon : weapons){
            weapon->update();
        }
        
    }
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(sprite);
    healthBar->render(target);
    xpBar->render(target);
    
    for (auto& weapon : weapons){
        weapon->render(target);
    }

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        hitBox.move(sf::Vector2f(0.f, -speed));
        sprite.setPosition(hitBox.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        hitBox.move(sf::Vector2f(0.f, speed));
        sprite.setPosition(hitBox.getPosition());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        hitBox.move(sf::Vector2f(-speed, 0.f));
        sprite.setPosition(hitBox.getPosition()); 
        
        if (facingRight){  
            sf::Vector2u textureSize = texture.getSize();
            sprite.setScale(
                {-(GameConstants::PLAYER_SIZE / textureSize.x),
                GameConstants::PLAYER_SIZE / textureSize.y}
            );
            facingRight = false;    
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        hitBox.move(sf::Vector2f(speed, 0.f));
        sprite.setPosition(hitBox.getPosition());
        if (!facingRight){   
            sf::Vector2u textureSize = texture.getSize();
            sprite.setScale(
                {(GameConstants::PLAYER_SIZE / textureSize.x),
                GameConstants::PLAYER_SIZE / textureSize.y}
            );
            facingRight = true;
        }
    }
}

void Player::getDamaged(float damage)
{
    health -= damage;
}

void Player::addXP(float amount)
{
    xp += amount;

    while (xp >= maxXP) {
        xp -= maxXP;
        levelUp();
}
}

int Player::getLevel() const
{
    return level; 
}

void Player::updateHealth(float addHealth)
{
    maxHealth += addHealth;
    health += addHealth / 2.f;
}

void Player::updateSpeed(float addSpeed)
{
    speed += addSpeed;
}

void Player::updateWeaponDamage(float addWeaponDamage)
{
    for (const auto& weapon : weapons){
        weapon->updateDamage(addWeaponDamage);
    }
}

bool Player::didLevelUp()
{
    if (levelUped){
        levelUped = false;
        return true;
    }else{
        return false;
    }
}

void Player::levelUp()
{
    level++;
    maxXP *= 1.2f;
    maxHealth += 20.0f;
    health += 50.0f;
    if (health > maxHealth) health = maxHealth;
    healthBar->setMaxHealth(maxHealth);
    healthBar->updateHealth(health);

    speed += 2.0f;
    levelUped  = true;
    xpBar->showLevelUpMessage();
}

// Knockback function

void Player::setKnockback(const sf::Vector2f& velocity)
{
    if (knockbackCooldown.getElapsedTime().asSeconds() > GameConstants::KNOCKBACK_COOLDOWN) {
        knockbackVelocity = velocity;
        knockbackCooldown.restart();
    }
}

void Player::move(const sf::Vector2f& offset)
{
    hitBox.move(offset);
    sprite.setPosition(hitBox.getPosition());
}

