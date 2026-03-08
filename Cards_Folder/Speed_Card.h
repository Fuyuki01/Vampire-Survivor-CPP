#pragma once
#include "Card.h"

class Speed_Card: public Card{
    public:
        Speed_Card();

        void apply(Player& player) override;

    protected:
        void initAppearance() override;

        void initText() override;
    
    private:
        float increaOnSpeed;

};
