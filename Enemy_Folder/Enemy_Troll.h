#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Player;

class Enemy_Troll: public Enemy{
    public:
        explicit Enemy_Troll(Player* player);

        void updateAppearance() override;

        void initliazeHitbox() override;
};
