/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*
NOTES :
    - gérer fin de game
        - 3 vies (difficulté normal)
        - 1 vie (difficulté hard)
    - enregistrer scores dans un fichier txt caché
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

static void help(void)
{
    my_putstr("\nWelcome in the Duck Hunt video game !\n\n");
    my_putstr("Rules :\n");
    my_putstr("    Your goal is to shoot ducks passing on your screen.\n");
    my_putstr("    The furthest you go in the game, ");
    my_putstr("the fastest and the most the ducks are.\n");
    my_putstr("You will lose if you let a duck cross the screen.\n");
    my_putstr("Inputs :\n");
    my_putstr("    './my_hunter -h' to get help.\n");
    my_putstr("Game created by Killian QUINTIN.\n");
}

int main(int ac, char **av)
{
    window_s window;
    bird_s *bird_tab = malloc(sizeof(bird_s) * 3);

    if (ac > 1 && my_strcmp(av[1], "-h") == 0) {
        help();
        return 0;
    }
    srand(time(NULL));
    init_window(&window);
    for (int i = 0; i < 3; i++)
        first_init_bird(&bird_tab[i], &window, i + 1);
    starting_screen(bird_tab, &window);
    free_all(bird_tab);
    return 0;
}
