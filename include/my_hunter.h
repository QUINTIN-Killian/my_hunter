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
#include <SFML/System/Clock.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

typedef struct audio {
    sfMusic *main_music;
    sfSound *gun_shot;
    sfSound *duck_noise;
} audio_s;

typedef struct background {
    sfTexture *background_texture;
    sfSprite *background_sprite;
} background_s;

typedef struct window {
    int score;
    sfRenderWindow *window_info;
    sfVector2u window_size;
    sfVideoMode video_mode;
    char *window_name;
} window_s;

typedef struct bird {
    int dir;
    sfTexture *bird_texture;
    sfSprite *bird_sprite;
    sfVector2f bird_pos;
} bird_s;

typedef struct score {
    sfText *score;
    sfFont *score_font;
    sfText *n_score;
    sfFont *n_score_font;
    sfVector2f n_score_pos;
    char *temp;
} score_s;

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

//audio.c :
void init_audio(audio_s *audio);

//background.c :
void init_background(background_s *background);

//window.c :
void init_window(window_s *window);

//bird.c :
void init_bird(bird_s *bird, window_s *window);
void place_bird(window_s *window, bird_s *bird);
void move_bird(window_s *window, bird_s *bird);

//rect.c :
void init_rect(sfIntRect *rect);
void move_rect(sfIntRect *rect, bird_s *bird, int offset, int max_value);

//score.c :
void init_score(score_s *score);
void print_score(score_s *score, window_s *window);

//music.c :
sfMusic *generate_main_music(void);
void gun_shot(audio_s *audio);
void duck_noise(audio_s *audio);

//my_hunter.c :
void main_loop(bird_s *bird, window_s *window, sfIntRect *rect);

//my_functions.c :
int my_randomizer(int nb);
char *convert_int_to_str(int nbr);

//events.c :
void get_event(window_s *window, bird_s *bird, audio_s *audio);

//destroy.c :
void destroy_all(background_s *background, score_s *score,
    bird_s *bird, audio_s *audio);

#endif
