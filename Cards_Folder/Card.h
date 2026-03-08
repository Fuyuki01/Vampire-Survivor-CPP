#pragma once
#include <SFML/Graphics.hpp>
#include "../Player.h"
#include "../Constants.h"
#include <iostream>
#include <vector>

class Card{
    public:
        Card();
        virtual ~Card() = default;

        void render(sf::RenderTarget* target);
        
        virtual void apply(Player& player) = 0;

        void setPosition(sf::Vector2f position);

    protected:
        virtual void initAppearance() = 0;

        virtual void initText() = 0;

        // Texture
        sf::Texture texture;
        
        // Sprite
        sf::Sprite sprite;

        // Text
        sf::Font font;
        std::vector<sf::Text> description;
        
};