#pragma once
#include "Weapon.h"

class Sword: public Weapon{
    public:
        explicit Sword(Player* player, const float damage);
        ~Sword() = default; 

        void updateAppearance() override;

};