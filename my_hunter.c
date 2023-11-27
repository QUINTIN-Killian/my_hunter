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

    if (window->score < 24) {
        ans = 0.1 - 0.01 * (window->score / 3);
    } else {
        ans = 0.025;
    }
    return ans;
}

static void bird_loop(bird_s *bird_tab, window_s *window, audio_s *audio)
{
    sfTime time;
    float seconds;

    for (int i = 0; i < window->nb_max_bird; i++) {
        time = sfClock_getElapsedTime(bird_tab[i].clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > get_velocity(window)) {
            move_rect(bird_tab[i].rect, &bird_tab[i]);
            move_bird(window, &bird_tab[i], audio);
            sfClock_restart(bird_tab[i].clock);
        }
        place_bird(window, &bird_tab[i]);
    }
}

static void main_loop1(window_s *window, background_s *background,
    heart_s *heart_tab, score_s *score)
{
    sfRenderWindow_clear(window->window_info, sfBlack);
    sfRenderWindow_drawSprite(window->window_info,
    background->background_sprite, NULL);
    print_lives(window, heart_tab);
    print_score(score, window);
}

static void main_loop2(window_s *window, bird_s *bird_tab, audio_s *audio)
{
    bird_loop(bird_tab, window, audio);
    sfRenderWindow_drawSprite(window->window_info,
    window->scope->scope_sprite, NULL);
    get_event(window, bird_tab, audio);
}

void main_loop(background_s *background, bird_s *bird_tab,
    window_s *window, audio_s *audio)
{
    score_s score;
    heart_s *heart_tab = malloc(sizeof(heart_s) * 3);

    init_score(&score);
    init_heart(heart_tab, window);
    while (sfRenderWindow_isOpen(window->window_info) && window->game_status) {
        main_loop1(window, background, heart_tab, &score);
        main_loop2(window, bird_tab, audio);
        sfRenderWindow_display(window->window_info);
    }
    end_screen(window, background, audio);
    destroy_game(&score, heart_tab);
}
