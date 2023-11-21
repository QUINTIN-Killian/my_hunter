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
    bird_s *bird_tab = malloc(sizeof(bird_s) * 10);
    sfIntRect rect;

    srand(time(NULL));
    init_window(&window);
    init_rect(&rect);
    for (int i = 0; i < 2; i++)
        first_init_bird(&bird_tab[i], &window, &rect, i + 1);
    main_loop(bird_tab, &window, &rect);
    free(bird_tab);
    return 0;
}
