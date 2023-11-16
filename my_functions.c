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
    srand(time(NULL));
    return (rand() % nb + 1);
}
