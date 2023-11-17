/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Generates the background.
** background
*/

#include "include/my.h"
#include "include/my_hunter.h"

void generate_main_theme_background(window_s *window)
{
    sfTexture *background_texture =
    sfTexture_createFromFile("images/my_hunter_background.jpg", NULL);
    sfSprite *background_sprite = sfSprite_create();

    sfSprite_setTexture(background_sprite, background_texture, sfFalse);
    sfRenderWindow_drawSprite(window->window_info, background_sprite, NULL);
}
