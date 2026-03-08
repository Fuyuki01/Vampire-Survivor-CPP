#pragma once
#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Constants.h"
#include <iostream>

class Card{
    public:
        Card();
        virtual ~Card() = default;

        void render(sf::RenderTarget* target);
        
        virtual void initAppearance() = 0;

        virtual void apply(Player& player) = 0;

        void setPosition(sf::Vector2f position);

    protected:
        // Texture
        sf::Texture texture;
        
        // Sprite
        sf::Sprite sprite;
        
};