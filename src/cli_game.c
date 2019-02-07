#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "ball.h"
#include "cli_ball.h"
#include "cli_platform.h"
#include "cli_game.h"
#include "cli_wall.h"
#include "window.h"

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
    printGameStatus(game);
    drawBall(&game->ball);
    drawPlatform(&game->platform);
    drawWall(&game->wall);

    refresh();
}

void printGameStatus(Game *game)
{
    printw("Level %d\n", game->level);
    printw("Window Size %d, %d\n", game->window.x, game->window.y);
    printw("Position %f, %f\n", game->ball.x, game->ball.y);
    printw("Platform %f\n", game->platform.x);
    printw("Angle %f", game->ball.angle);
}

void endGameGraphics()
{
    endwin();
}