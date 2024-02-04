/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the lives of the player.
** heart
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_heart(heart_s *heart_tab, window_s *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window->window_info);

    for (int i = 0; i < window->lives; i++) {
        heart_tab[i].heart_scale.x = 0.05;
        heart_tab[i].heart_scale.y = 0.05;
        heart_tab[i].heart_pos.x = window_size.x - 30 - i * 30;
        heart_tab[i].heart_pos.y = 0;
        heart_tab[i].heart_texture =
        sfTexture_createFromFile("images/red_heart2.png", NULL);
        heart_tab[i].heart_sprite = sfSprite_create();
    }
}

void print_lives(window_s *window, heart_s *heart_tab)
{
    for (int i = 0; i < 3 - window->lives; i++) {
        sfTexture_destroy(heart_tab[i].heart_texture);
        sfSprite_destroy(heart_tab[i].heart_sprite);
        heart_tab[i].heart_texture =
        sfTexture_createFromFile("images/grey_heart2.png", NULL);
        heart_tab[i].heart_sprite = sfSprite_create();
    }
    for (int i = 0; i < 3; i++) {
        sfSprite_setScale(heart_tab[i].heart_sprite,
        heart_tab[i].heart_scale);
        sfSprite_setPosition(heart_tab[i].heart_sprite,
        heart_tab[i].heart_pos);
        sfSprite_setTexture(heart_tab[i].heart_sprite,
        heart_tab[i].heart_texture, sfFalse);
        sfRenderWindow_drawSprite(window->window_info,
        heart_tab[i].heart_sprite, NULL);
    }
}
