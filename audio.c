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
    audio->gun_shot_buff = sfSoundBuffer_createFromFile("music/gun_shot.ogg");
    audio->duck_noise_buff =
    sfSoundBuffer_createFromFile("music/duck_noise.wav");
    audio->buzzer_sound_buff =
    sfSoundBuffer_createFromFile("music/buzzer_sound.ogg");
    audio->gun_shot = sfSound_create();
    audio->duck_noise = sfSound_create();
    audio->buzzer_sound = sfSound_create();
    audio->main_music = generate_main_music();
    sfSound_setBuffer(audio->gun_shot, audio->gun_shot_buff);
    sfSound_setBuffer(audio->duck_noise, audio->duck_noise_buff);
    sfSound_setBuffer(audio->buzzer_sound, audio->buzzer_sound_buff);
}

sfMusic *generate_main_music(void)
{
    sfMusic *main_music =
    sfMusic_createFromFile("music/main_theme_music.flac");

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

void buzzer_sound(audio_s *audio)
{
    sfSound_play(audio->buzzer_sound);
}
