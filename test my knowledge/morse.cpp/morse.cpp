#include "splashkit.h"

int main()
{
    // Copy "ACoolSong.ogg" to Resources/music
    // Copy "MoodSettingMusic.ogg" to Resources/music

    load_sound_effect("x", "morse_dit.ogg");
    load_sound_effect("y","morse_dah.ogg");


    //H
    play_sound_effect("x");
    delay(200);
    play_sound_effect("x");
    delay(200);
    play_sound_effect("x");
    delay(200);
    play_sound_effect("x");
    delay(1000);

    //E
    play_sound_effect("x");
    delay(1000);

    //L
    play_sound_effect("x");
    delay(200);
    play_sound_effect("y");
    delay(200);
    play_sound_effect("x");
    delay(200);
    play_sound_effect("x");
    delay(1000);

    //L
    play_sound_effect("x");
    delay(200);
    play_sound_effect("y");
    delay(200);
    play_sound_effect("x");
    delay(200);
    play_sound_effect("x");
    delay(1000);

    //O
    play_sound_effect("y");
    delay(200);
    play_sound_effect("y");
    delay(200);
    play_sound_effect("y");
    delay(200);


    
    delay(2500);
}