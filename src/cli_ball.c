#include <ncurses.h>
#include "cli_ball.h"

void drawBall(Ball *ball)
{
    mvprintw(ball->y, ball->x, "o");
}