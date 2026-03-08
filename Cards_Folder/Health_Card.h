#pragma once
#include "Card.h"

class Health_Card : public Card{
    public:
        Health_Card();

        void initAppearance() override;

        void apply(Player& player) override;
    private: 
        float increaOnHealth;
};