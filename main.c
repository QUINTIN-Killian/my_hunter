/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*
NOTES :
    - gérer vélocité oiseaux (changer timer bird_loop() de 0.1s)
        - 3 premiers = vélocité de 0.1
        - 10 suivants = vélocité de 0.01 et il peut y
        en avoir plusieurs (max 2)
        - 7 suivants = vélocité de 0.005 et il peut y
        en avoir plsuieurs (max 3)
    - gérer fin de game
        - 3 vies (difficulté normal)
        - 1 vie (difficulté hard)
    - faire que les touches <- et -> permettent de changer la musique
    - faire spawn oiseaux des deux cotés
    - faire apparaître plusieurs oiseaux
    - changer curseur in game
    - easter egg changement de langue
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
