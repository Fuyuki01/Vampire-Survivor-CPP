#pragma once
#include "Weapon.h"

class Sword: public Weapon{
    public:
        explicit Sword(Player* player, const float damage);
        ~Sword() = default; 

        int returnDamage() override;

        void updateAppearance() override;

    protected:
        void updateAnimation() override;

    private:
        void attack() override;

        void initializeHitbox() override;

        void updateSwing();

        sf::Vector2f decideAttackPosition();

        sf::Angle swingAngle;

};