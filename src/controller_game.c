#include <stdbool.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "ball.h"
#include "window.h"
#include "platform.h"
#include "wall.h"
#include "controller_game.h"
#include "cli_game.h"
#include "cli_window.h"

void initGame(Game *game)
{
    Ball ball;
    Window window;
    Platform platform;
    Wall wall;

    srand(time(NULL));

    initGameGraphics();
    initWindow(&window);
    initBall(&ball, &window);
    initPlatform(&platform, &window);
    initWall(&wall);

    game->ball = ball;
    game->window = window;
    game->platform = platform;
    game->wall = wall;
    game->level = 1;
    game->life = 3;
}

void startGame(Game *game)
{
    int userCommand;
    bool inGame = true;

    while (userCommand != 'q')
    {
        drawGame(game);
        inGame = platformCollision(&game->ball, &game->platform);
        if (inGame == false)
        {
            break;
        }
        wallCollision(&game->ball, &game->wall);
        movePlatform(&game->platform, &game->window, userCommand);
        moveBallForward(&game->ball, &game->window);
        userCommand = getch();
        usleep(REFRESH_RATE);
    }

    while (userCommand != 'q')
    {
        userCommand = getch();
        usleep(REFRESH_RATE);
    }
}

void endGame()
{
    endGameGraphics();
}