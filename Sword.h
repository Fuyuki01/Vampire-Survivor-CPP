#pragma once
#include "Weapon.h"

class Sword: public Weapon{
    public:
        explicit Sword(Player* player, const float damage);
        ~Sword() = default; 

        int returnDamage() override;

        void updateAppearance() override;

    private:
        void attack() override;

        void initializeHitbox() override;

        sf::Vector2f decideAttackPosition();

};