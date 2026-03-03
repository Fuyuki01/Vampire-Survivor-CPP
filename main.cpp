#include "MainMenu.h"
#include "Game.h"
#include "GameOver.h"

int main() {
    bool continuePlaying = true;

    while (continuePlaying) {
        MainMenu menu;
        bool playSelected = menu.run();

        if (!playSelected) {
            break;
        }

        Game game;
        while (game.windowIsOpen()) {
            game.update();
            game.render();
        }

        if (game.isTotalDeath()) {
            GameOver gameOver;
            bool returnToMenu = gameOver.run();

            if (!returnToMenu) {

                break;
            }
        }
    }

    return 0;
}