/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Displays the starting screen.
** starting_game
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void leave_game(window_s *window, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) || event.type == sfEvtClosed) {
        sfRenderWindow_close(window->window_info);
    }
}

static void lauch_game(window_s *window, bird_s *bird_tab,
    sfEvent event, audio_s *audio)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        main_loop(bird_tab, window, audio);
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
        bird->clock = sfClock_create();
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

void get_start_event(window_s *window, bird_s *bird_tab,
    audio_s *audio, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        leave_game(window, event);
        lauch_game(window, bird_tab, event, audio);
        sound(&event, audio);
        volume(&event, audio);
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
    sfRenderWindow_display(window->window_info);
}

void starting_screen(bird_s *bird_tab, window_s *window)
{
    sfEvent event;
    background_s background;
    display_start_s display_start;
    bird_s bird;
    audio_s audio;

    init_audio(&audio);
    init_bird_start(&bird, window);
    init_start(&display_start, window);
    init_background(&background);
    while (sfRenderWindow_isOpen(window->window_info) && window->game_status) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        starting_screen_display(window, &background, &display_start, &bird);
        get_start_event(window, bird_tab, &audio, event);
    }
    destroy_start(&background, &bird, &display_start);
}
