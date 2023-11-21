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

void move_rect(sfIntRect *rect, bird_s *bird, int offset, int max_value)
{
    if (bird->dir) {
        rect->left = rect->left + max_value / offset;
        if (rect->left >= max_value) {
            bird->dir = 0;
            rect->left = rect->left - (max_value / offset * 2);
        }
    } else {
        rect->left = rect->left - max_value / offset;
        if (rect->left == 0)
            bird->dir = 1;
    }
}
