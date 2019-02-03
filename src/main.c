#include "game.h"
#include "controller_game.h"

int main()
{
    Game game;

    initGame(&game);
    startGame(&game);
    endGame();

    return 0;
}
