/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Contains event functions.
** events
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void close_window(sfEvent *event, window_s *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window->window_info);
}

static void mouse_click(sfEvent *event, window_s *window, bird_s *bird)
{
    sfVector2i mouse_pos;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPositionRenderWindow(window->window_info);
        if (mouse_pos.x >= bird->bird_pos.x &&
        mouse_pos.x <= bird->bird_pos.x + 110 &&
        mouse_pos.y >= bird->bird_pos.y &&
        mouse_pos.y <= bird->bird_pos.y + 110) {
            init_bird(bird, window);
        }
    }
}

static void sound(sfEvent *event, sfMusic *main_music)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sfMusic_getStatus(main_music) == sfPaused) {
            sfMusic_play(main_music);
            return;
        }
        if (sfMusic_getStatus(main_music) == sfPlaying) {
            sfMusic_pause(main_music);
            return;
        }
    }
}

void get_event(window_s *window, bird_s *bird, sfMusic *main_music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        close_window(&event, window);
        mouse_click(&event, window, bird);
        sound(&event, main_music);
    }
}
