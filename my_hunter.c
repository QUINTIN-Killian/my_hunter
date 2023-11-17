/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Initiation in CSFML.
** initiation_CSFML
*/

#include "include/my_hunter.h"
#include "include/my.h"

static void bird_loop(sfClock *clock, bird_s *bird,
    window_s *window, sfIntRect *rect)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 1 / bird->velocity) {
        move_rect(rect, bird, 3, 330);
        place_bird(window, bird);
        move_bird(window, bird);
        sfRenderWindow_display(window->window_info);
        sfClock_restart(clock);
    }
}

void main_loop(bird_s *bird, window_s *window, sfIntRect *rect)
{
    sfClock *clock;

    clock = sfClock_create();
    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        generate_main_theme_background(window);
        sfSprite_setTextureRect(bird->bird_sprite, *rect);
        get_event(window->window_info);
        bird_loop(clock, bird, window, rect);
    }
}
