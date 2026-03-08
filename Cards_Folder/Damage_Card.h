#pragma once
#include "Card.h"

class Damage_Card: public Card{
    public:
        Damage_Card();

        void initAppearance() override;

        void apply(Player& player) override;

    private:
        float increaseOnDamage;

};