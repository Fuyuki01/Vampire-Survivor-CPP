#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Player;

class Enemy_Goblin: public Enemy{
    public:
        explicit Enemy_Goblin(Player* player);

        void updateAppearance() override;

};