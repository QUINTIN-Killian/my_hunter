/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains auxiliar functions.
** my_functions
*/

#include "include/my.h"
#include "include/my_hunter.h"

int my_randomizer(int nb)
{
    return (rand() % nb + 1);
}

char *convert_int_to_str(int nbr)
{
    int intlen = my_intlen(nbr);
    char *str = malloc(sizeof(char) * (intlen + 1));
    int n = 1;

    for (int i = 0; i < intlen; i++) {
        str[i] = nbr / my_compute_power_rec(10, intlen - n) + 48;
        nbr = nbr - (nbr / my_compute_power_rec(10, intlen - n) *
        my_compute_power_rec(10, intlen - n));
        n++;
    }
    str[intlen] = '\0';
    return str;
}

void change_nb_max_bird(window_s *window)
{
    if (window->score == 5) {
        window->nb_max_bird = window->nb_max_bird + 1;
        return;
    }
    if (window->score == 14) {
        window->nb_max_bird = window->nb_max_bird + 1;
        return;
    }
}
