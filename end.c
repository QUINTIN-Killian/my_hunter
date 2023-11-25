/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the start display.
** start
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void set_end(end_s *end)
{
    sfText_setFillColor(end->game_over, sfMagenta);
    sfText_setFont(end->game_over, end->game_over_font);
    sfText_setString(end->game_over, "GAME OVER");
    sfText_setOutlineThickness(end->game_over, 1.0);
    sfText_setScale(end->game_over, (sfVector2f){3.0, 3.0});
    sfText_setFillColor(end->infos, sfCyan);
    sfText_setFont(end->infos, end->infos_font);
    sfText_setString(end->infos,
    "(Shoot the duck to go back to the main menu or press 'escape' to leave)");
    sfText_setOutlineThickness(end->infos, 1.0);
    sfText_setScale(end->infos, (sfVector2f){0.7, 0.7});
    sfText_setPosition(end->game_over, end->game_over_pos);
    sfText_setPosition(end->infos, end->infos_pos);
}

void init_end(end_s *end, window_s *window)
{
    end->game_over = sfText_create();
    end->game_over_font = sfFont_createFromFile("font/impact.ttf");
    end->game_over_pos = (sfVector2f){100, 100};
    end->infos = sfText_create();
    end->infos_font = sfFont_createFromFile("font/impact.ttf");
    end->infos_pos = (sfVector2f){window->window_size.x - 620,
    window->window_size.y - 30};
    set_end(end);
}
