/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*COMPILATION AVEC : 'gcc <files> -lcsfml-graphics'*/
/*
NOTES :
    - sfTexture_destroy(bird->bird_texture);
*/

#include "include/my.h"
#include "include/my_hunter.h"

int main(int ac, char **av)
{
    window_s window;
    bird_s bird;
    sfIntRect rect;

    init_window(&window);
    init_bird(&bird, &window, 5);
    init_rect(&rect);
    main_loop(&bird, &window, &rect);
    return 0;
}
