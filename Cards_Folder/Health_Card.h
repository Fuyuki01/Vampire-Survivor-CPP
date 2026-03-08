#pragma once
#include "Card.h"

class Health_Card : public Card{
    public:
        Health_Card();

        void apply(Player& player) override;

    protected:
        void initAppearance() override;
        
        void initText() override;
        
    private: 
        float increaOnHealth;
};