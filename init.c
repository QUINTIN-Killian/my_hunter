/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Initialize structs.
** init
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_background(background_s *background)
{
    background->background_texture =
    sfTexture_createFromFile("images/my_hunter_background.jpg", NULL);
    background->background_sprite = sfSprite_create();
    sfSprite_setTexture(background->background_sprite,
    background->background_texture, sfFalse);
}

void init_window(window_s *window)
{
    window->video_mode.height = 600;
    window->video_mode.width = 800;
    window->video_mode.bitsPerPixel = 64;
    window->window_name = "VideoGame - DUCK HUNT (created by Killian QUINTIN)";
    window->window_info = sfRenderWindow_create(window->video_mode,
    window->window_name, sfClose, NULL);
    window->window_size = sfRenderWindow_getSize(window->window_info);
}

void init_bird(bird_s *bird, window_s *window, int coef)
{
    bird->dir = 1;
    bird->coef = coef;
    bird->velocity = 10 + my_randomizer(bird->coef);
    bird->bird_pos.x = -50;
    bird->bird_pos.y = my_randomizer(
    sfRenderWindow_getSize(window->window_info).y - 110);
}

void init_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
}
