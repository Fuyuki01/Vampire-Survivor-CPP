#include "MainMenu.h"
#include "Game.h"
#include "SettingMenu.h"
#include "GameOver.h"
#include "Settings.h"

int main() {
    bool continuePlaying = true;

    Settings settings;

    while (continuePlaying) {
        MainMenu menu(&settings);
        int selected = menu.run();

        if (selected == 2) {
            // Exit
            break;
        }else if (selected == 1){
            // Settings
            SettingMenu setingsMenu(&settings, &menu);
            setingsMenu.run();
        }

        if (selected == 0){
            // Play
            Game game(&settings);
            while (game.windowIsOpen()) {
                game.update();
                game.render();
            }

            if (game.isTotalDeath()) {
                GameOver gameOver(&settings);
                bool returnToMenu = gameOver.run();

                if (!returnToMenu) {
                    break;
                }
            }
        }
       
    }

    return 0;
}