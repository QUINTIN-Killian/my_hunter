/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Initiation in CSFML.
** initiation_CSFML
*/

#include "include/my_hunter.h"
#include "include/my.h"

static float get_velocity(window_s *window)
{
    float ans;

    if (window->score < 27) {
        ans = 0.1 - 0.01 * (window->score / 3);
    } else {
        ans = 0.02;
    }
    return ans;
}

static void bird_loop(bird_s *bird_tab,
    window_s *window, sfIntRect *rect)
{
    sfTime time;
    float seconds;

    for (int i = 0; i < 2; i++) {
        time = sfClock_getElapsedTime(bird_tab[i].clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > get_velocity(window)) {
            move_rect(rect, &bird_tab[i]);
            move_bird(window, &bird_tab[i]);
            sfClock_restart(bird_tab[i].clock);
        }
        place_bird(window, &bird_tab[i]);
    }
}

void main_loop(bird_s *bird_tab, window_s *window, sfIntRect *rect)
{
    background_s background;
    audio_s audio;
    score_s score;

    init_background(&background);
    init_audio(&audio);
    init_score(&score);
    while (sfRenderWindow_isOpen(window->window_info) && window->game_status) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfRenderWindow_drawSprite(window->window_info,
        background.background_sprite, NULL);
        print_score(&score, window);
        bird_loop(bird_tab, window, rect);
        get_event(window, bird_tab, &audio);
        sfRenderWindow_display(window->window_info);
    }
    destroy_all(&background, &score, bird_tab, &audio);
}
