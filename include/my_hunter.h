/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Header for my_hunter project.
** my_hunter
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
    sfSoundBuffer *gun_shot_buff;
    sfSoundBuffer *duck_noise_buff;
    sfSoundBuffer *buzzer_sound_buff;
    sfMusic *main_music;
    sfSound *gun_shot;
    sfSound *duck_noise;
    sfSound *buzzer_sound;
} audio_s;

typedef struct background {
    sfTexture *background_texture;
    sfSprite *background_sprite;
} background_s;

typedef struct scope {
    sfTexture *scope_texture;
    sfSprite *scope_sprite;
    sfVector2f scope_pos;
} scope_s;

typedef struct pause {
    sfText *pause;
    sfFont *pause_font;
    sfVector2f pause_pos;
    sfText *continue_;
    sfFont *continue_font;
    sfVector2f continue_pos;
    sfText *end_game;
    sfFont *end_game_font;
    sfVector2f end_game_pos;
    sfText *leave;
    sfFont *leave_font;
    sfVector2f leave_pos;
} pause_s;

typedef struct window {
    int restart;
    int start;
    int pause;
    int lives;
    int nb_max_bird;
    int game_status;
    int score;
    int nb_shot;
    float velocity;
    sfRenderWindow *window_info;
    sfVector2u window_size;
    sfVideoMode video_mode;
    char *window_name;
    scope_s *scope;
} window_s;

typedef struct bird {
    sfIntRect *rect;
    sfClock *clock;
    int dir;
    sfTexture *bird_texture;
    sfSprite *bird_sprite;
    sfVector2f bird_pos;
} bird_s;

typedef struct score {
    sfText *score;
    sfFont *score_font;
    sfVector2f score_pos;
    sfText *n_score;
    sfFont *n_score_font;
    sfVector2f n_score_pos;
    char *temp;
} score_s;

typedef struct heart {
    sfVector2f heart_scale;
    sfVector2f heart_pos;
    sfTexture *heart_texture;
    sfSprite *heart_sprite;
} heart_s;

typedef struct display_start {
    sfText *game_name;
    sfFont *game_name_font;
    sfVector2f game_name_pos;
    sfText *launch_info;
    sfFont *launch_info_font;
    sfVector2f launch_info_pos;
} display_start_s;

typedef struct end {
    char *temp;
    sfText *game_over;
    sfFont *game_over_font;
    sfVector2f game_over_pos;
    sfText *infos;
    sfFont *infos_font;
    sfVector2f infos_pos;
    sfText *score;
    sfFont *score_font;
    sfVector2f score_pos;
    sfText *n_score;
    sfFont *n_score_font;
    sfVector2f n_score_pos;
    sfText *shots;
    sfFont *shots_font;
    sfVector2f shots_pos;
    sfText *n_shots;
    sfFont *n_shots_font;
    sfVector2f n_shots_pos;
    sfText *best_score;
    sfFont *best_score_font;
    sfVector2f best_score_pos;
    sfText *n_best_score;
    sfFont *n_best_score_font;
    sfVector2f n_best_score_pos;
} end_s;

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

//audio.c :
void init_audio(audio_s *audio);
sfMusic *generate_main_music(void);
void gun_shot(audio_s *audio);
void duck_noise(audio_s *audio);
void buzzer_sound(audio_s *audio);

//background.c :
void init_background(background_s *background);

//best_score.c :
int get_file_size(void);
char *get_nb_file(void);
void refresh_file(int file_nb, int nb_comp);

//bird.c :
void first_init_bird(bird_s *bird, window_s *window, int i);
void init_bird(bird_s *bird, window_s *window);
void place_bird(window_s *window, bird_s *bird);
void move_bird(window_s *window, bird_s *bird, audio_s *audio);

//destroy.c :
void destroy_main_end(window_s *window, bird_s *bird_tab);
void destroy_main(window_s *window, bird_s *bird_tab);
void destroy_start(background_s *background, display_start_s *display_start,
    bird_s *bird, audio_s *audio);
void destroy_game(score_s *score, heart_s *heart_tab);
void destroy_end(end_s *end, bird_s *bird);

//end.c :
void init_end(end_s *end, window_s *window);

//events.c :
void sound(sfEvent *event, audio_s *audio);
void volume(sfEvent *event, audio_s *audio);
void move_mouse(sfEvent *event, window_s *window);
void get_event(window_s *window, bird_s *bird, audio_s *audio);

//heart.c :
void init_heart(heart_s *heart_tab, window_s *window);
void print_lives(window_s *window, heart_s *heart_tab);

//my_functions.c :
int my_randomizer(int nb);
char *convert_int_to_str(int nbr);
void change_nb_max_bird(window_s *window);

//pause.c :
void init_pause_menu(pause_s *pause);
void display_pause(pause_s *pause, window_s *window);
void destroy_pause(pause_s *pause, bird_s *bird_tab);

//rect.c :
void init_rect(bird_s *bird);
void move_rect(sfIntRect *rect, bird_s *bird);

//scope.c :
void init_scope(window_s *window);

//score.c :
void init_score(score_s *score);
void print_score(score_s *score, window_s *window);

//start.c :
void init_start(display_start_s *display_start, window_s *window);

//window.c :
void init_window(window_s *window);
void reinit_window(window_s *window);

//starting_game.c :
void starting_screen(bird_s *bird_tab, window_s *window);

//my_hunter.c :
void main_loop(background_s *background, bird_s *bird_tab,
    window_s *window, audio_s *audio);

//pause_menu.c :
void pause_menu(window_s *window, background_s *background, audio_s *audio);

//end_game.c :
void end_screen(window_s *window, background_s *background, audio_s *audio);

#endif
