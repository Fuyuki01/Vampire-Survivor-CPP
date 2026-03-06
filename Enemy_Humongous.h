#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Player;

class Enemy_Humongous: public Enemy{
    public:
        explicit Enemy_Humongous(Player* player);

        void updateAppearance() override;

        void initliazeHitbox() override;
};