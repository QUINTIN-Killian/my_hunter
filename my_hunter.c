/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Initiation in CSFML.
** initiation_CSFML
*/

#include "include/my_hunter.h"
#include "include/my.h"

static void change_velocity(window_s *window)
{
    if (window->score == 3)
        window->velocity = 0.04;
    if (window->score == 4)
        window->velocity = 0.01;
    if (window->score == 13)
        window->velocity = 0.0085;
    if (window->score == 14)
        window->velocity = 0.0075;
    if (window->score == 20)
        window->velocity = 0.007;
    if (window->score == 21)
        window->velocity = 0.005;
}

static void bird_loop(sfClock *clock, bird_s *bird,
    window_s *window, sfIntRect *rect)
{
    sfTime time;
    float seconds;

    change_velocity(window);
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > window->velocity) {
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
    audio_s audio;
    score_s score;

    init_background(&background);
    init_audio(&audio);
    init_score(&score);
    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfRenderWindow_drawSprite(window->window_info,
        background.background_sprite, NULL);
        print_score(&score, window);
        sfSprite_setTextureRect(bird->bird_sprite, *rect);
        bird_loop(clock, bird, window, rect);
        get_event(window, bird, &audio);
    }
    destroy_all(&background, &score, bird, &audio);
}
