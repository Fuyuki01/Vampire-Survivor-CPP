#pragma once
#include "Card.h"

class Weapons_Card : public Card{
    public:
        Weapons_Card();

        void apply(Player& player) override;

    protected:
        void initAppearance() override;

        void initText() override;
    
    private:
        int increaseOnWeapon;
};