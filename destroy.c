/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Destroys.
** destroy
*/

#include "include/my.h"
#include "include/my_hunter.h"

void destroy_main_end(window_s *window, bird_s *bird_tab)
{
    free(bird_tab);
    sfTexture_destroy(window->scope->scope_texture);
    sfSprite_destroy(window->scope->scope_sprite);
    free(window->scope);
    sfRenderWindow_destroy(window->window_info);
}

void destroy_main(bird_s *bird_tab)
{
    for (int i = 0; i < 3; i++) {
        free(bird_tab[i].rect);
        sfClock_destroy(bird_tab[i].clock);
        sfTexture_destroy(bird_tab[i].bird_texture);
        sfSprite_destroy(bird_tab[i].bird_sprite);
    }
}

void destroy_start(background_s *background, display_start_s *display_start,
    bird_s *bird, audio_s *audio)
{
    sfTexture_destroy(background->background_texture);
    sfSprite_destroy(background->background_sprite);
    sfTexture_destroy(display_start->exit_texture);
    sfSprite_destroy(display_start->exit_sprite);
    sfText_destroy(display_start->game_name);
    sfFont_destroy(display_start->game_name_font);
    sfText_destroy(display_start->launch_info);
    sfFont_destroy(display_start->launch_info_font);
    free(bird->rect);
    sfTexture_destroy(bird->bird_texture);
    sfSprite_destroy(bird->bird_sprite);
    sfClock_destroy(bird->clock);
    sfSoundBuffer_destroy(audio->gun_shot_buff);
    sfSoundBuffer_destroy(audio->duck_noise_buff);
    sfSoundBuffer_destroy(audio->buzzer_sound_buff);
    sfSound_destroy(audio->gun_shot);
    sfSound_destroy(audio->duck_noise);
    sfSound_destroy(audio->buzzer_sound);
    sfMusic_destroy(audio->main_music);
}

void destroy_game(score_s *score, heart_s *heart_tab)
{
    sfText_destroy(score->score);
    sfFont_destroy(score->score_font);
    sfText_destroy(score->n_score);
    sfFont_destroy(score->n_score_font);
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(heart_tab[i].heart_texture);
        sfSprite_destroy(heart_tab[i].heart_sprite);
    }
    free(heart_tab);
}

static void destroy_end_text(end_s *end)
{
    sfText_destroy(end->game_over);
    sfFont_destroy(end->game_over_font);
    sfText_destroy(end->infos);
    sfFont_destroy(end->infos_font);
    sfText_destroy(end->score);
    sfFont_destroy(end->score_font);
    sfText_destroy(end->n_score);
    sfFont_destroy(end->n_score_font);
    sfText_destroy(end->shots);
    sfFont_destroy(end->shots_font);
    sfText_destroy(end->n_shots);
    sfFont_destroy(end->n_shots_font);
    sfText_destroy(end->best_score);
    sfFont_destroy(end->best_score_font);
    sfText_destroy(end->n_best_score);
    sfFont_destroy(end->n_best_score_font);
}

void destroy_end(end_s *end, bird_s *bird)
{
    sfTexture_destroy(end->exit_texture);
    sfSprite_destroy(end->exit_sprite);
    destroy_end_text(end);
    free(bird->rect);
    sfTexture_destroy(bird->bird_texture);
    sfSprite_destroy(bird->bird_sprite);
    sfClock_destroy(bird->clock);
}
