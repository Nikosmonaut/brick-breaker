#include <ncurses.h>

#include "window.h"

void initWindow(Window *window)
{
    getmaxyx(stdscr, window->y, window->x);
}