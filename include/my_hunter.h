/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Header for my_hunter project.
** my_hunter
*/

#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct window {
    sfRenderWindow *window_info;
    sfVector2u window_size;
    sfVideoMode video_mode;
    char *window_name;
} window_s;

typedef struct bird {
    sfTexture *bird_texture;
    sfSprite * bird_sprite;
    sfVector2f bird_pos;
} bird_s;

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

//init.c :
void init_window(window_s *window);
void init_bird(bird_s *bird, window_s *window);
void init_rect(sfIntRect *rect);

//my_hunter.c :
void window_opening(bird_s *bird, window_s *window, sfIntRect *rect);

//my_functions.c :
int my_randomizer(int nb);

//events.c :
void get_event(sfRenderWindow *window);

//bird.c :
void place_bird(window_s *window, bird_s *bird);
void move_bird(window_s *window, bird_s *bird);

//rect.c :
void move_rect(sfIntRect *rect, bird_s *bird, int offset, int max_value);

#endif
