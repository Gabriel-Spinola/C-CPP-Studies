#include "Game.h"

#define _WIN64_WINNT 0x0500
#include <windows.h>

int main()
{
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Initialize game object
    Game game;

    // Game Loop
    while(game.IsRunning()) {
        game.Update();
        game.Render();
    }

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    return 0;
}