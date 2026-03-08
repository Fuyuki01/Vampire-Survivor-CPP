#pragma once
#include "Card.h"

class Speed_Card: public Card{
    public:
        Speed_Card();

        void initAppearance() override;

        void apply(Player& player) override;
    
    private:
        float increaOnSpeed;

};
