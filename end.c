/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the start display.
** start
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void init_main_display_end(window_s *window, end_s *end)
{
    end->game_over = sfText_create();
    end->game_over_font = sfFont_createFromFile("font/impact.ttf");
    end->game_over_pos = (sfVector2f){100, 100};
    sfText_setFillColor(end->game_over, sfMagenta);
    sfText_setFont(end->game_over, end->game_over_font);
    sfText_setString(end->game_over, "GAME OVER");
    sfText_setOutlineThickness(end->game_over, 1.0);
    sfText_setScale(end->game_over, (sfVector2f){3.0, 3.0});
    sfText_setPosition(end->game_over, end->game_over_pos);
    end->infos = sfText_create();
    end->infos_font = sfFont_createFromFile("font/impact.ttf");
    end->infos_pos = (sfVector2f){window->window_size.x - 620,
    window->window_size.y - 30};
    sfText_setFillColor(end->infos, sfCyan);
    sfText_setFont(end->infos, end->infos_font);
    sfText_setString(end->infos,
    "(Shoot the duck to go back to the main menu or press 'escape' to leave)");
    sfText_setOutlineThickness(end->infos, 1.0);
    sfText_setScale(end->infos, (sfVector2f){0.7, 0.7});
    sfText_setPosition(end->infos, end->infos_pos);
}

static void init_end_score(window_s *window, end_s *end)
{
    end->score = sfText_create();
    end->score_font = sfFont_createFromFile("font/impact.ttf");
    end->score_pos = (sfVector2f){100, 220};
    sfText_setFillColor(end->score, sfMagenta);
    sfText_setFont(end->score, end->score_font);
    sfText_setString(end->score, "- Final score : ");
    sfText_setOutlineThickness(end->score, 1.0);
    sfText_setPosition(end->score, end->score_pos);
    end->n_score = sfText_create();
    end->n_score_font = sfFont_createFromFile("font/impact.ttf");
    end->n_score_pos = (sfVector2f){270, 220};
    sfText_setFillColor(end->n_score, sfMagenta);
    sfText_setFont(end->n_score, end->n_score_font);
    end->temp = convert_int_to_str(window->score);
    sfText_setString(end->n_score, end->temp);
    sfText_setOutlineThickness(end->n_score, 1.0);
    sfText_setPosition(end->n_score, end->n_score_pos);
    free(end->temp);
}

static void init_end_shots(window_s *window, end_s *end)
{
    end->shots = sfText_create();
    end->shots_font = sfFont_createFromFile("font/impact.ttf");
    end->shots_pos = (sfVector2f){100, 250};
    sfText_setFillColor(end->shots, sfMagenta);
    sfText_setFont(end->shots, end->shots_font);
    sfText_setString(end->shots, "- Total number of shots : ");
    sfText_setOutlineThickness(end->shots, 1.0);
    sfText_setPosition(end->shots, end->shots_pos);
    end->n_shots = sfText_create();
    end->n_shots_font = sfFont_createFromFile("font/impact.ttf");
    end->n_shots_pos = (sfVector2f){410, 250};
    sfText_setFillColor(end->n_shots, sfMagenta);
    sfText_setFont(end->n_shots, end->n_shots_font);
    end->temp = convert_int_to_str(window->nb_shot);
    sfText_setString(end->n_shots, end->temp);
    sfText_setOutlineThickness(end->n_shots, 1.0);
    sfText_setPosition(end->n_shots, end->n_shots_pos);
    free(end->temp);
}

void init_end(end_s *end, window_s *window)
{
    init_main_display_end(window, end);
    init_end_score(window, end);
    init_end_shots(window, end);
}
