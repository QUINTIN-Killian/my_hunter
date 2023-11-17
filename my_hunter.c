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
    if (seconds > 0.1) {
        move_rect(rect, bird, 3, 330);
        place_bird(window, bird);
        move_bird(window, bird);
        sfRenderWindow_display(window->window_info);
        sfClock_restart(clock);
    }
}

void main_loop(bird_s *bird, window_s *window, sfIntRect *rect)
{
    sfClock *clock = sfClock_create();
    background_s background;
    sfMusic *main_music = generate_main_music();

    init_background(&background);
    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfRenderWindow_drawSprite(window->window_info,
        background.background_sprite, NULL);
        sfSprite_setTextureRect(bird->bird_sprite, *rect);
        bird_loop(clock, bird, window, rect);
        get_event(window, bird, main_music);
    }
    sfSprite_destroy(background.background_sprite);
    sfSprite_destroy(bird->bird_sprite);
    sfMusic_destroy(main_music);
}
