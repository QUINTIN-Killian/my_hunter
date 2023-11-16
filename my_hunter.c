/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Initiation in CSFML.
** initiation_CSFML
*/

#include "include/my_hunter.h"
#include "include/my.h"

void window_opening(bird_s *bird, window_s *window, sfIntRect *rect)
{
    sfClock *clock;
    sfTime time;
    float seconds;

    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfSprite_setTextureRect(bird->bird_sprite, *rect);
        move_rect(rect, bird, 3, 330);
        place_bird(window, bird);
        move_bird(window, bird);
        get_event(window->window_info);
        sfRenderWindow_display(window->window_info);
        sleep(1);
    }
}
