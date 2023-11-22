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
        en avoir plusieurs (max 3)
    - gérer fin de game
        - 3 vies (difficulté normal)
        - 1 vie (difficulté hard)
    - fix taille du fichier de la musique principale
    - faire que les touches <- et -> permettent de changer la musique
    - changer curseur in game
    - easter egg changement de langue
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void free_all(bird_s *bird_tab)
{
    for (int i = 0; i < 3; i++)
        free(bird_tab[i].rect);
    free(bird_tab);
}

int main(int ac, char **av)
{
    window_s window;
    bird_s *bird_tab = malloc(sizeof(bird_s) * 3);

    srand(time(NULL));
    init_window(&window);
    for (int i = 0; i < 3; i++)
        first_init_bird(&bird_tab[i], &window, i + 1);
    main_loop(bird_tab, &window);
    free_all(bird_tab);
    return 0;
}
