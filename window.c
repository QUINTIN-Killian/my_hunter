/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Manages the window.
** window
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_window(window_s *window)
{
    window->restart = 1;
    window->start = 0;
    window->lives = 3;
    window->nb_max_bird = 1;
    window->game_status = 1;
    window->score = 0;
    window->velocity = 0.1;
    window->video_mode.height = 600;
    window->video_mode.width = 800;
    window->video_mode.bitsPerPixel = 64;
    window->window_name = "DUCK HUNT (created by Killian QUINTIN)";
    window->window_info = sfRenderWindow_create(window->video_mode,
    window->window_name, sfClose, NULL);
    window->window_size = sfRenderWindow_getSize(window->window_info);
}

void reinit_window(window_s *window)
{
    window->start = 0;
    window->lives = 3;
    window->nb_max_bird = 1;
    window->game_status = 1;
    window->score = 0;
    window->velocity = 0.1;
}
