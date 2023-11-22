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
    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->window_info);
}

static void mouse_click(sfEvent *event, window_s *window,
    bird_s *bird, audio_s *audio)
{
    sfVector2i mouse_pos;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPositionRenderWindow(window->window_info);
        gun_shot(audio);
        if (mouse_pos.x >= bird->bird_pos.x &&
        mouse_pos.x <= bird->bird_pos.x + 110 &&
        mouse_pos.y >= bird->bird_pos.y &&
        mouse_pos.y <= bird->bird_pos.y + 110) {
            duck_noise(audio);
            init_bird(bird, window);
            window->score++;
            change_nb_max_bird(window);
        }
    }
}

static void sound(sfEvent *event, audio_s *audio)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sfMusic_getStatus(audio->main_music) == sfPaused) {
            sfMusic_play(audio->main_music);
            return;
        }
        if (sfMusic_getStatus(audio->main_music) == sfPlaying) {
            sfMusic_pause(audio->main_music);
            return;
        }
    }
}

static void volume(sfEvent *event, audio_s *audio)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfMusic_setVolume(audio->main_music,
        sfMusic_getVolume(audio->main_music) + 5.0);
        sfSound_setVolume(audio->gun_shot,
        sfSound_getVolume(audio->gun_shot) + 5.0);
        sfSound_setVolume(audio->duck_noise,
        sfSound_getVolume(audio->duck_noise) + 5.0);
        return;
    }
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfMusic_setVolume(audio->main_music,
        sfMusic_getVolume(audio->main_music) - 5.0);
        sfSound_setVolume(audio->gun_shot,
        sfSound_getVolume(audio->gun_shot) - 5.0);
        sfSound_setVolume(audio->duck_noise,
        sfSound_getVolume(audio->duck_noise) - 5.0);
        return;
    }
}

void get_event(window_s *window, bird_s *bird_tab, audio_s *audio)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        close_window(&event, window);
        sound(&event, audio);
        volume(&event, audio);
        for (int i = 0; i < 3; i++)
            mouse_click(&event, window, &bird_tab[i], audio);
    }
}
