/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Manages the background.
** background
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
