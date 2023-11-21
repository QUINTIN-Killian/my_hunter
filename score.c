/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Manages the score.
** score
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_score(score_s *score)
{
    score->score = sfText_create();
    score->score_font = sfFont_createFromFile("font/impact.ttf");
    score->n_score = sfText_create();
    score->n_score_font = sfFont_createFromFile("font/impact.ttf");
    score->n_score_pos.x = -100;
    score->n_score_pos.y = 0;
    sfText_setOrigin(score->n_score, score->n_score_pos);
    sfText_setFillColor(score->score, sfYellow);
    sfText_setFont(score->score, score->score_font);
    sfText_setFillColor(score->n_score, sfYellow);
    sfText_setFont(score->n_score, score->n_score_font);
}

void print_score(score_s *score, window_s *window)
{
    sfText_setString(score->score, "Score : ");
    sfRenderWindow_drawText(window->window_info, score->score, NULL);
    score->temp = convert_int_to_str(window->score);
    sfText_setString(score->n_score, score->temp);
    sfRenderWindow_drawText(window->window_info, score->n_score, NULL);
    free(score->temp);
}
