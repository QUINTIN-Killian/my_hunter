/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains all rect actions.
** bird
*/

#include "include/my.h"
#include "include/my_hunter.h"

void move_rect(sfIntRect *rect, bird_s *bird, int offset, int max_value)
{
    rect->left = rect->left + 110;
    if (rect->left >= max_value)
        init_rect(rect);
}
