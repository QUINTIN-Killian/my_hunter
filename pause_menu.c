/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Manages the pause menu
** pause_menu
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void leave_game(window_s *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window->window_info);
    }
}

static void init_bird_rect_pause(bird_s *bird)
{
    bird->rect = malloc(sizeof(sfIntRect));
    bird->rect->top = 0;
    bird->rect->left = 0;
    bird->rect->width = 110;
    bird->rect->height = 110;
}

static void init_bird_tab_pause(bird_s *bird_tab)
{
    for (int i = 0; i < 3; i++) {
        init_bird_rect_pause(&bird_tab[i]);
        bird_tab[i].bird_texture =
        sfTexture_createFromFile("images/bird.png", NULL);
        bird_tab[i].bird_sprite = sfSprite_create();
        sfSprite_setTextureRect(bird_tab[i].bird_sprite, *bird_tab[i].rect);
        bird_tab[i].clock = sfClock_create();
        bird_tab[i].bird_pos = (sfVector2f){140 + (i * 100) * 2, 350};
    }
}

static void bird_loop_pause(bird_s *bird_tab, window_s *window)
{
    sfTime time;
    float seconds;

    for (int i = 0; i < 3; i++) {
        time = sfClock_getElapsedTime(bird_tab[i].clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(bird_tab[i].rect, &bird_tab[i]);
            sfClock_restart(bird_tab[i].clock);
        }
        place_bird(window, &bird_tab[i]);
    }
}

static int hit_bird(window_s *window,
    audio_s *audio, bird_s *bird_tab)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    for (int i = 0; i < 3; i++) {
        if (mouse_pos.x >= bird_tab[i].bird_pos.x &&
            mouse_pos.x <= bird_tab[i].bird_pos.x + 110 &&
            mouse_pos.y >= bird_tab[i].bird_pos.y &&
            mouse_pos.y <= bird_tab[i].bird_pos.y + 110) {
            duck_noise(audio);
            return i;
        }
    }
    return -1;
}

int kill_pause_bird(sfEvent *event, window_s *window,
    audio_s *audio, bird_s *bird_tab)
{
    int temp;

    if (event->type == sfEvtMouseButtonPressed) {
        gun_shot(audio);
        temp = hit_bird(window, audio, bird_tab);
        if (temp != -1)
            return temp;
    }
    return -1;
}

int get_pause_event(window_s *window, bird_s *bird_tab,
    audio_s *audio, sfEvent event)
{
    int evt = -1;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        move_mouse(&event, window);
        leave_game(window, event);
        sound(&event, audio);
        volume(&event, audio);
        evt = kill_pause_bird(&event, window, audio, bird_tab);
    }
    return evt;
}

void analyse_evt(int evt, window_s *window)
{
    if (evt == 0) {
        window->pause = 0;
        return;
    }
    if (evt == 1) {
        window->pause = 0;
        window->game_status = 0;
        return;
    }
    if (evt == 2) {
        sfRenderWindow_close(window->window_info);
        return;
    }
}

void pause_menu(window_s *window, background_s *background, audio_s *audio)
{
    sfEvent event;
    pause_s pause;
    bird_s *bird_tab_pause = malloc(sizeof(bird_s) * 3);

    init_pause_menu(&pause);
    init_bird_tab_pause(bird_tab_pause);
    while (sfRenderWindow_isOpen(window->window_info) && window->pause) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfRenderWindow_drawSprite(window->window_info,
        background->background_sprite, NULL);
        bird_loop_pause(bird_tab_pause, window);
        display_pause(&pause, window);
        sfRenderWindow_drawSprite(window->window_info,
        window->scope->scope_sprite, NULL);
        analyse_evt(get_pause_event(window,
        bird_tab_pause, audio, event), window);
        sfRenderWindow_display(window->window_info);
    }
    destroy_pause(&pause, bird_tab_pause);
}
