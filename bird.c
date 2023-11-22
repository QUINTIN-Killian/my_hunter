/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains all bird actions.
** bird
*/

#include "include/my.h"
#include "include/my_hunter.h"

void first_init_bird(bird_s *bird, window_s *window, sfIntRect *rect, int i)
{
    bird->dir = my_randomizer(2);
    if (bird->dir == 1)
        bird->bird_texture =
        sfTexture_createFromFile("images/bird.png", NULL);
    else
        bird->bird_texture =
        sfTexture_createFromFile("images/bird_inv.png", NULL);
    bird->bird_sprite = sfSprite_create();
    sfSprite_setTextureRect(bird->bird_sprite, *rect);
    bird->clock = sfClock_create();
    if (bird->dir == 1)
        bird->bird_pos.x = my_randomizer(300) * (-1) - 100 * i;
    else
        bird->bird_pos.x = my_randomizer(300) +
        sfRenderWindow_getSize(window->window_info).x + 100 * i;
    bird->bird_pos.y = my_randomizer(
    sfRenderWindow_getSize(window->window_info).y - 110);
}

static void set_bird_pos(bird_s *bird, window_s *window, int temp)
{
    if (bird->dir == 1) {
        bird->bird_pos.x = my_randomizer(300) * (-1) - 100;
        if (bird->dir != temp) {
            sfTexture_destroy(bird->bird_texture);
            bird->bird_texture =
            sfTexture_createFromFile("images/bird.png", NULL);
        }
    } else {
        bird->bird_pos.x = my_randomizer(300) +
        sfRenderWindow_getSize(window->window_info).x + 100;
        if (bird->dir != temp) {
            sfTexture_destroy(bird->bird_texture);
            bird->bird_texture =
            sfTexture_createFromFile("images/bird_inv.png", NULL);
        }
    }
    bird->bird_pos.y = my_randomizer(
    sfRenderWindow_getSize(window->window_info).y - 110);
}

void init_bird(bird_s *bird, window_s *window)
{
    int temp = bird->dir;

    bird->dir = my_randomizer(2);
    bird->clock = sfClock_create();
    set_bird_pos(bird, window, temp);
}

void place_bird(window_s *window, bird_s *bird)
{
    sfSprite_setPosition(bird->bird_sprite, bird->bird_pos);
    sfSprite_setTexture(bird->bird_sprite, bird->bird_texture, sfFalse);
    sfRenderWindow_drawSprite(window->window_info, bird->bird_sprite, NULL);
}

void move_bird(window_s *window, bird_s *bird)
{
    if (bird->bird_pos.x >= window->window_size.x + 100 && bird->dir == 1) {
        window->game_status = 0;
        return;
    }
    if (bird->bird_pos.x <= 0 - 100 && bird->dir == 2) {
        window->game_status = 0;
        return;
    }
    if (bird->dir == 1)
        bird->bird_pos.x += 10;
    else
        bird->bird_pos.x -= 10;
}
