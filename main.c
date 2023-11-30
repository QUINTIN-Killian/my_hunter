/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*
NOTES :
    BONUS :
        - easter egg changement de langue
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void print_help(void)
{
    my_putstr("Welcome in the Duck Hunt video game !\n\n");
    my_putstr("Rules :\n");
    my_putstr("    Your goal is to shoot ducks while ");
    my_putstr(    "crossing on your screen.\n");
    my_putstr("    The furthest you go in the game, ");
    my_putstr(    "the fastest and the most the ducks are.\n");
    my_putstr("    You will lose if you let 3 ducks cross the screen.\n");
    my_putstr("Inputs :\n");
    my_putstr("    './my_hunter -h' to get help.\n");
    my_putstr("Commands :\n");
    my_putstr("    Press 'escape' in game to open the pause menu.\n");
    my_putstr("    Press 'space' in game to turn on/off the main music.\n");
    my_putstr("    Press 'up-arrow' in game to put up the volume.\n");
    my_putstr("    Press 'down-arrow' in game to put down the volume.\n");
    my_putstr("Game created by Killian QUINTIN.\n");
}

static int flags(int ac, char **av)
{
    if (ac > 1 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return 1;
    }
    return 0;
}

static int is_paqueta(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-paqueta") == 0)
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    window_s window;
    bird_s *bird_tab = malloc(sizeof(bird_s) * 3);

    if (flags(ac, av))
        return 0;
    srand(time(NULL));
    init_window(&window);
    sfRenderWindow_setMouseCursorVisible(window.window_info, sfFalse);
    while (window.restart) {
        window.restart = 0;
        for (int i = 0; i < 3; i++)
            first_init_bird(&bird_tab[i], &window, i + 1);
        starting_screen(bird_tab, &window, is_paqueta(ac, av));
        destroy_main(bird_tab);
        reinit_window(&window);
    }
    destroy_main_end(&window, bird_tab);
    return 0;
}
