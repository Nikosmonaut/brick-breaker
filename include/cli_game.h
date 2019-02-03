#ifndef CLI_GAME_H_INCLUDED
#define CLI_GAME_H_INCLUDED

#include "window.h"
#include "ball.h"
#include "game.h"

void initGameGraphics();
void drawGame(Game *game);
void printGameStatus(Game *game);
void endGameGraphics();

#endif