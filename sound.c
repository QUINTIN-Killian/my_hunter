/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Generates the sounds.
** sound
*/

#include "include/my.h"
#include "include/my_hunter.h"

sfMusic *generate_main_music(void)
{
    sfMusic *main_music = sfMusic_createFromFile("music/main_theme_music.wav");

    sfMusic_play(main_music);
    sfMusic_setLoop(main_music, sfTrue);
    return main_music;
}
