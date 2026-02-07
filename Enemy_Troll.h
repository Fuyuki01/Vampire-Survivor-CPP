#pragma once
#include "Enemy.h"

class Player;

class Enemy_Troll: public Enemy{
    public:
        explicit Enemy_Troll(Player* player);

        void updateAppearance() override;
};
