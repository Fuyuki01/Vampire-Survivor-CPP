#include "MainMenu.h"
#include "Game.h"
#include "SettingMenu.h"
#include "GameOver.h"

int main() {
    bool continuePlaying = true;

    while (continuePlaying) {
        MainMenu menu;
        int selected = menu.run();

        if (selected == 2) {
            // Exit
            break;
        }else if (selected == 1){
            // Settings
            SettingMenu setings(&menu);
            setings.run();
        }

        Game game;
        if (selected == 0){
            // Play
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
       
    }

    return 0;
}