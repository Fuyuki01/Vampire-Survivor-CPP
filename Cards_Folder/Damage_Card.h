#pragma once
#include "Card.h"

class Damage_Card: public Card{
    public:
        Damage_Card();

        void apply(Player& player) override;

    protected:
        void initAppearance() override;

        void initText() override;

    private:
        float increaseOnDamage;

};