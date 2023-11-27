/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the start display.
** start
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void set_start(display_start_s *display_start)
{
    sfText_setFillColor(display_start->game_name, sfMagenta);
    sfText_setFont(display_start->game_name, display_start->game_name_font);
    sfText_setString(display_start->game_name, "Duck Hunt");
    sfText_setOutlineThickness(display_start->game_name, 1.0);
    sfText_setCharacterSize(display_start->game_name, 100);
    sfText_setFillColor(display_start->launch_info, sfCyan);
    sfText_setFont(display_start->launch_info,
    display_start->launch_info_font);
    sfText_setString(display_start->launch_info,
    "(Shoot the duck to start or press 'escape' to leave)");
    sfText_setOutlineThickness(display_start->launch_info, 1.0);
    sfText_setCharacterSize(display_start->launch_info, 19);
    sfText_setPosition(display_start->game_name,
    display_start->game_name_pos);
    sfText_setPosition(display_start->launch_info,
    display_start->launch_info_pos);
}

void init_start(display_start_s *display_start, window_s *window)
{
    display_start->game_name = sfText_create();
    display_start->game_name_font = sfFont_createFromFile("font/impact.ttf");
    display_start->game_name_pos = (sfVector2f){100, 100};
    display_start->launch_info = sfText_create();
    display_start->launch_info_font = sfFont_createFromFile("font/impact.ttf");
    display_start->launch_info_pos = (sfVector2f){window->window_size.x - 420,
    window->window_size.y - 30};
    set_start(display_start);
}
