#include "Weapon.h"
#include "Player.h"

Weapon::Weapon(Player *player, const float damage): texture(), sprite(texture), damage(damage){
    playerPointer = player;
    cooldownTime = 2.f;
    durationTime = 2.f;
    attackAnimationTime = durationTime;
    active = false;
    
    cooldown.restart();
    attackDuration.restart();
}

void Weapon::update()
{
    if (cooldown.getElapsedTime().asSeconds() >= cooldownTime and !active){
        active = true;
        attackDuration.restart();
        attack();
    }

    if (active){
        updateAnimation();
    }

    if (attackDuration.getElapsedTime().asSeconds() >= durationTime and active){
        active = false;
        cooldown.restart();
    }
}

void Weapon::render(sf::RenderTarget *target)
{
    if (active){
        target->draw(sprite);
    }
}

void Weapon::updateDamage(float addWeaponDamage)
{
    damage += addWeaponDamage;
}

sf::Rect<float> Weapon::returnBounds()
{
    return hitBox.getGlobalBounds();
}

bool Weapon::isActive() const
{
    return active;
}
