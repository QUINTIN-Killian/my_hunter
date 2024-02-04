/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Init the pause menu.
** pause
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void init_pause(pause_s *pause)
{
    pause->pause = sfText_create();
    pause->pause_font = sfFont_createFromFile("font/impact.ttf");
    pause->pause_pos = (sfVector2f){260, 100};
    sfText_setFillColor(pause->pause, sfMagenta);
    sfText_setFont(pause->pause, pause->pause_font);
    sfText_setString(pause->pause, "PAUSE");
    sfText_setOutlineThickness(pause->pause, 1.0);
    sfText_setCharacterSize(pause->pause, 100);
    sfText_setPosition(pause->pause,
    pause->pause_pos);
}

static void init_continue(pause_s *pause)
{
    pause->continue_ = sfText_create();
    pause->continue_font = sfFont_createFromFile("font/impact.ttf");
    pause->continue_pos = (sfVector2f){130, 450};
    sfText_setFillColor(pause->continue_, sfMagenta);
    sfText_setFont(pause->continue_, pause->continue_font);
    sfText_setString(pause->continue_, "continue");
    sfText_setOutlineThickness(pause->continue_, 1.0);
    sfText_setPosition(pause->continue_,
    pause->continue_pos);
}

static void init_fast_end_game(pause_s *pause)
{
    pause->end_game = sfText_create();
    pause->end_game_font = sfFont_createFromFile("font/impact.ttf");
    pause->end_game_pos = (sfVector2f){330, 450};
    sfText_setFillColor(pause->end_game, sfMagenta);
    sfText_setFont(pause->end_game, pause->end_game_font);
    sfText_setString(pause->end_game, "end game");
    sfText_setOutlineThickness(pause->end_game, 1.0);
    sfText_setPosition(pause->end_game,
    pause->end_game_pos);
}

static void init_leave(pause_s *pause)
{
    pause->leave = sfText_create();
    pause->leave_font = sfFont_createFromFile("font/impact.ttf");
    pause->leave_pos = (sfVector2f){520, 450};
    sfText_setFillColor(pause->leave, sfMagenta);
    sfText_setFont(pause->leave, pause->leave_font);
    sfText_setString(pause->leave, "leave game");
    sfText_setOutlineThickness(pause->leave, 1.0);
    sfText_setPosition(pause->leave,
    pause->leave_pos);
}

void init_pause_menu(pause_s *pause)
{
    init_pause(pause);
    init_continue(pause);
    init_fast_end_game(pause);
    init_leave(pause);
}

void display_pause(pause_s *pause, window_s *window)
{
    sfRenderWindow_drawText(window->window_info, pause->pause, NULL);
    sfRenderWindow_drawText(window->window_info, pause->continue_, NULL);
    sfRenderWindow_drawText(window->window_info, pause->end_game, NULL);
    sfRenderWindow_drawText(window->window_info, pause->leave, NULL);
}

void destroy_pause(pause_s *pause, bird_s *bird_tab)
{
    sfText_destroy(pause->pause);
    sfFont_destroy(pause->pause_font);
    sfText_destroy(pause->continue_);
    sfFont_destroy(pause->continue_font);
    sfText_destroy(pause->end_game);
    sfFont_destroy(pause->end_game_font);
    sfText_destroy(pause->leave);
    sfFont_destroy(pause->leave_font);
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(bird_tab[i].bird_texture);
        sfSprite_destroy(bird_tab[i].bird_sprite);
        sfClock_destroy(bird_tab[i].clock);
        free(bird_tab[i].rect);
    }
    free(bird_tab);
}
