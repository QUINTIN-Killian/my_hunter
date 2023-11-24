/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Destroys.
** destroy
*/

#include "include/my.h"
#include "include/my_hunter.h"

void destroy_heart(heart_s *heart_tab)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(heart_tab[i].heart_texture);
        sfSprite_destroy(heart_tab[i].heart_sprite);
    }
}

void destroy_start(background_s *background, bird_s *bird,
    display_start_s *display_start)
{
    sfSprite_destroy(background->background_sprite);
    sfTexture_destroy(background->background_texture);
    sfSprite_destroy(bird->bird_sprite);
    sfTexture_destroy(bird->bird_texture);
    sfText_destroy(display_start->game_name);
    sfFont_destroy(display_start->game_name_font);
    sfText_destroy(display_start->launch_info);
    sfFont_destroy(display_start->launch_info_font);
}

void destroy_all(background_s *background, score_s *score,
    bird_s *bird_tab, audio_s *audio)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(bird_tab[i].bird_sprite);
        sfTexture_destroy(bird_tab[i].bird_texture);
    }
    sfSprite_destroy(background->background_sprite);
    sfTexture_destroy(background->background_texture);
    sfMusic_destroy(audio->main_music);
    sfSound_destroy(audio->gun_shot);
    sfSound_destroy(audio->duck_noise);
    sfText_destroy(score->score);
    sfText_destroy(score->n_score);
}
