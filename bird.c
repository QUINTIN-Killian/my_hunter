/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains all bird actions.
** bird
*/

#include "include/my.h"
#include "include/my_hunter.h"

void place_bird(window_s *window, bird_s *bird)
{
    sfSprite_setPosition(bird->bird_sprite, bird->bird_pos);
    sfSprite_setTexture(bird->bird_sprite, bird->bird_texture, sfFalse);
    sfRenderWindow_drawSprite(window->window_info, bird->bird_sprite, NULL);
}

void move_bird(window_s *window, bird_s *bird)
{
    if (bird->bird_pos.x >= window->window_size.x) {
        init_bird(bird, window);
    } else {
        bird->bird_pos.x += 10;
    }
}
