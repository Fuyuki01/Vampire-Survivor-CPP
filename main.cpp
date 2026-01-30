#include "Game.h"

int main(){
    Game game;
 
    while(game.windowIsOpen())
    {
            // Update
            game.update();

            // Render
            game.render();
            
    }
    
}
