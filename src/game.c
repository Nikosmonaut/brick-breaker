#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ball.h>
#include <window.h>
#include <game.h>

#define SPEED 15000

void initGame()
{
    int userCommand;
    Ball ball;
    WindowSize windowSize;

    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    clear();
    nodelay(stdscr, TRUE);

    getmaxyx(stdscr, windowSize.y, windowSize.x);

    initBall(&ball, &windowSize);

    while (userCommand != 'A')
    {
        clear();
        printw("Window Size %d, %d\n", windowSize.x, windowSize.y);
        printw("Position %d, %d\n", ball.x, ball.y);
        printw("Offset %d", ball.offset);

        drawBall(&ball);
        refresh();
        usleep(SPEED);
        nextStep(&ball, &windowSize);
        userCommand = getch();
    }

}

void startGame()
{
}

void endGame()
{
    endwin();
}