#pragma once
#include <SFML/Graphics.hpp>

class Player;

class XPBar: public sf::RectangleShape{
    public:
        XPBar(float xp, Player* player);
        ~XPBar();

        void updateXp(float xp);
        void update();
        void render(sf::RenderTarget* target);

    private:
        sf::Vector2f xpSize;
        sf::RectangleShape background;

        Player* playerPointer;

        void initBackgournd();

};