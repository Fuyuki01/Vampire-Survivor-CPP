#include "MainMenu.h"
#include "Game.h"

int main() {
    MainMenu menu;
    if (!menu.run()) return 0;

    Game game;
    while (game.windowIsOpen()) {
        game.update();
        game.render();
    }

    return 0;
}