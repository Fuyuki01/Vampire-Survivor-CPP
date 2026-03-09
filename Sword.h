#pragma once
#include "Weapon.h"

class Sword: public Weapon{
    public:
        explicit Sword(Player* player, const float damage);
        ~Sword() = default; 

        int returnDamage() override;

        void updateAppearance() override;

        std::unique_ptr<Weapon> clone() const override;

    protected:
        void updateAnimation(int index, int weaponCount) override;
        
    private:
        void attack() override;

        void initializeHitbox() override;

        void updateSwing();

        sf::Vector2f decideAttackPosition();

        sf::Angle swingAngle;

};