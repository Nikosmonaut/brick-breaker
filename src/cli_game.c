#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "ball.h"
#include "cli_ball.h"
#include "window.h"
#include "controller_game.h"

void initGameGraphics()
{
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    clear();
    nodelay(stdscr, TRUE);
}

void drawGame(Game *game)
{
    clear();
    drawBall(&game->ball);
    printGameStatus(game);
    refresh();
}

void printGameStatus(Game *game)
{
    printw("Window Size %d, %d\n", game->window.x, game->window.y);
    printw("Position %d, %d\n", game->ball.x, game->ball.y);
    printw("Offset %d", game->ball.offset);
}

void endGameGraphics()
{
    endwin();
}