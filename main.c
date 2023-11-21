/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*
NOTES :
    - gérer vélocité oiseaux
    - faire spawn oiseaux des deux cotés
    - faire apparaître plusieurs oiseaux
    - changer curseur in game
*/

#include "include/my.h"
#include "include/my_hunter.h"

int main(int ac, char **av)
{
    window_s window;
    bird_s bird;
    sfIntRect rect;

    init_window(&window);
    bird.bird_texture = sfTexture_createFromFile("images/bird.png", NULL);
    bird.bird_sprite = sfSprite_create();
    init_bird(&bird, &window);
    init_rect(&rect);
    main_loop(&bird, &window, &rect);
    return 0;
}
