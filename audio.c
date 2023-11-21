/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_
** File description:
** Generates the audio.
** audio
*/

#include "include/my.h"
#include "include/my_hunter.h"

void init_audio(audio_s *audio)
{
    audio->gun_shot = sfSound_create();
    audio->duck_noise = sfSound_create();
    audio->main_music = generate_main_music();
    sfSound_setBuffer(audio->gun_shot,
    sfSoundBuffer_createFromFile("music/gun_shot.ogg"));
    sfSound_setBuffer(audio->duck_noise,
    sfSoundBuffer_createFromFile("music/duck_noise.wav"));
}

sfMusic *generate_main_music(void)
{
    sfMusic *main_music = sfMusic_createFromFile("music/main_theme_music.wav");

    sfMusic_setVolume(main_music, 50.0);
    sfMusic_play(main_music);
    sfMusic_setLoop(main_music, sfTrue);
    return main_music;
}

void gun_shot(audio_s *audio)
{
    sfSound_play(audio->gun_shot);
}

void duck_noise(audio_s *audio)
{
    sfSound_play(audio->duck_noise);
}
