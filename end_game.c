/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-killian.quintin
** File description:
** Displays the starting screen.
** starting_game
*/

#include "include/my.h"
#include "include/my_hunter.h"

static void leave_game(window_s *window, end_s *end, sfEvent event)
{
    sfVector2i mouse_pos;

    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(window->window_info);
        return;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPositionRenderWindow(window->window_info);
        if (mouse_pos.x >= end->exit_pos.x &&
        mouse_pos.x <= end->exit_pos.x + 110 &&
        mouse_pos.y >= end->exit_pos.y &&
        mouse_pos.y <= end->exit_pos.y + 110) {
            sfRenderWindow_close(window->window_info);
            return;
        }
    }
}

static void print_end_stat(end_s *end, window_s *window)
{
    sfRenderWindow_drawText(window->window_info, end->game_over, NULL);
    sfRenderWindow_drawText(window->window_info, end->infos, NULL);
    sfRenderWindow_drawText(window->window_info, end->score, NULL);
    sfRenderWindow_drawText(window->window_info, end->n_score, NULL);
    sfRenderWindow_drawText(window->window_info, end->best_score, NULL);
    sfRenderWindow_drawText(window->window_info, end->n_best_score, NULL);
    sfRenderWindow_drawText(window->window_info, end->shots, NULL);
    sfRenderWindow_drawText(window->window_info, end->n_shots, NULL);
}

static void init_bird_end(bird_s *bird, window_s *window)
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

static void move_bird_end(bird_s *bird, window_s *window)
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

static void bird_loop_end(bird_s *bird, window_s *window)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(bird->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        move_rect(bird->rect, bird);
        move_bird_end(bird, window);
        sfClock_restart(bird->clock);
    }
    place_bird(window, bird);
}

void kill_end_bird(sfEvent *event, window_s *window,
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
            window->restart = 1;
        }
    }
}

void get_end_event(window_s *window, end_s *end, bird_s *bird,
    audio_s *audio)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        move_mouse(&event, window);
        leave_game(window, end, event);
        sound(&event, audio);
        volume(&event, audio);
        kill_end_bird(&event, window, audio, bird);
    }
}

void end_screen_display(window_s *window, background_s *background,
    end_s *end, bird_s *bird)
{
    sfRenderWindow_drawSprite(window->window_info,
    background->background_sprite, NULL);
    print_end_stat(end, window);
    bird_loop_end(bird, window);
    sfRenderWindow_drawSprite(window->window_info,
    end->exit_sprite, NULL);
    sfRenderWindow_drawSprite(window->window_info,
    window->scope->scope_sprite, NULL);
}

void end_screen(window_s *window, background_s *background, audio_s *audio)
{
    end_s end;
    bird_s bird;
    char *file_str = get_nb_file();
    int file_nb = convert_str_in_int(file_str);

    refresh_file(file_nb, window->score);
    init_end(&end, window);
    init_bird_end(&bird, window);
    while (sfRenderWindow_isOpen(window->window_info) && !window->restart) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        end_screen_display(window, background, &end, &bird);
        get_end_event(window, &end, &bird, audio);
        sfRenderWindow_display(window->window_info);
    }
    free(file_str);
    destroy_end(&end, &bird);
}
