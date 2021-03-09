#include "Game.h"

int main()
{
    // init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    // Init Game engine
    Game game;

    // Game Loop
    while(game.Running() && !game.GetEndGame()) {
        // Update
        game.Update();

        // Render
        game.Render();
    }

    // End of Application
    return 0;
}