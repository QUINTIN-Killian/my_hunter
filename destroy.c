/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Destroys.
** destroy
*/

#include "include/my.h"
#include "include/my_hunter.h"

void destroy_all(background_s *background, score_s *score,
    bird_s *bird_tab, audio_s *audio)
{
    for (int i = 0; i < 2; i++) {
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
