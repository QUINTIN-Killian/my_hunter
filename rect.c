/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains all rect actions.
** bird
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
}

void move_rect(sfIntRect *rect, bird_s *bird)
{
    rect->left = rect->left + 110;
    if (rect->left >= 330)
        rect->left = 0;
    sfSprite_setTextureRect(bird->bird_sprite, *rect);
}
