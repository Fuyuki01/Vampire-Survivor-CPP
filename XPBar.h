#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Player;

class XPBar: public sf::RectangleShape{
    public:
        XPBar(float xp, Player* player);
        ~XPBar();

        void updateXp(float xp);
        void update();
        void render(sf::RenderTarget* target);

        void showLevelUpMessage();
        void initLevelUp();
        void showLevelText();

    private:
        sf::Vector2f xpBarSize;
        sf::RectangleShape background;

        sf::Font font;
        std::unique_ptr<sf::Text> levelUpText;
        std::unique_ptr<sf::Text> levelText;
        bool showMessage;
        sf::Clock messageTimer;
        const float MESSAGE_DURATION = 2.0f;

        Player* playerPointer;

        int height;
        int width;

        void initBackground(float xp);

};