/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains event functions.
** events
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void close_window(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void get_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        close_window(&event, window);
}
