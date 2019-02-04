#include <ncurses.h>
#include "cli_ball.h"

void drawBall(Ball *ball)
{
    mvaddch(ball->y, ball->x, 'o');
}