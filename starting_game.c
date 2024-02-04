/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Displays the starting screen.
** starting_game
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void leave_game(window_s *window,
    display_start_s *display_start, sfEvent event)
{
    sfVector2i mouse_pos;

    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(window->window_info);
        return;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPositionRenderWindow(window->window_info);
        if (mouse_pos.x >= display_start->exit_pos.x &&
        mouse_pos.x <= display_start->exit_pos.x + 110 &&
        mouse_pos.y >= display_start->exit_pos.y &&
        mouse_pos.y <= display_start->exit_pos.y + 110) {
            sfRenderWindow_close(window->window_info);
            return;
        }
    }
}

static void init_bird_start(bird_s *bird, window_s *window)
{
    init_rect(bird);
    bird->dir = 1;
    bird->bird_texture =
    sfTexture_createFromFile("images/bird.png", NULL);
    bird->bird_sprite = sfSprite_create();
    sfSprite_setTextureRect(bird->bird_sprite, *bird->rect);
    bird->clock = sfClock_create();
    bird->bird_pos = (sfVector2f){-130, window->window_size.y - 200};
}

static void move_bird_start(bird_s *bird, window_s *window)
{
    if (bird->bird_pos.x >= window->window_size.x + 120) {
        sfClock_restart(bird->clock);
        bird->bird_pos = (sfVector2f){-130, window->window_size.y - 200};
        return;
    }
    if (bird->dir == 1)
        bird->bird_pos.x += 10;
    else
        bird->bird_pos.x -= 10;
}

static void bird_loop_start(bird_s *bird, window_s *window)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(bird->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        move_rect(bird->rect, bird);
        move_bird_start(bird, window);
        sfClock_restart(bird->clock);
    }
    place_bird(window, bird);
}

void kill_start_bird(sfEvent *event, window_s *window,
    audio_s *audio, bird_s *bird)
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
            window->start = 1;
        }
    }
}

void get_start_event(window_s *window, display_start_s *display_start,
    bird_s *bird, audio_s *audio)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        move_mouse(&event, window);
        leave_game(window, display_start, event);
        sound(&event, audio);
        volume(&event, audio);
        kill_start_bird(&event, window, audio, bird);
    }
}

void starting_screen_display(window_s *window, background_s  *background,
    display_start_s *display_start, bird_s *bird)
{
    sfRenderWindow_drawSprite(window->window_info,
    background->background_sprite, NULL);
    sfRenderWindow_drawText(window->window_info,
    display_start->game_name, NULL);
    sfRenderWindow_drawText(window->window_info,
    display_start->launch_info, NULL);
    bird_loop_start(bird, window);
    sfRenderWindow_drawSprite(window->window_info,
    display_start->exit_sprite, NULL);
    sfRenderWindow_drawSprite(window->window_info,
    window->scope->scope_sprite, NULL);
}

void starting_screen(bird_s *bird_tab, window_s *window, int n)
{
    background_s background;
    display_start_s display_start;
    bird_s bird;
    audio_s audio;

    init_background(&background);
    init_start(&display_start, window);
    init_bird_start(&bird, window);
    init_audio(&audio, n);
    while (sfRenderWindow_isOpen(window->window_info) && window->game_status) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        starting_screen_display(window, &background, &display_start, &bird);
        get_start_event(window, &display_start, &bird, &audio);
        sfRenderWindow_display(window->window_info);
        if (window->start)
            main_loop(&background, bird_tab, window, &audio);
    }
    destroy_start(&background, &display_start, &bird, &audio);
}
