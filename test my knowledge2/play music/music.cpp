#include "splashkit.h"




int main()
{
    string path;
    string name;
    string user_input;
    double music1, music2;
    double seconds;
    
    write_line("Welcome to the music play test");

    
    write_line("What file would you like to load? Enter path: ");
    path = read_line();

    write_line("What should I call this music? Enter name: ");
    name = read_line();

    
    write_line("Loading " + name + " music from " + path);
    load_sound_effect(name, path);

    
    write_line("How long do you want to play it for? Enter seconds: ");
    user_input = read_line();
    seconds = to_double(user_input);

    write_line("At what initial volume? Enter percent (0 to 1): ");
    user_input = read_line();
    music1 = to_double(user_input);


    write_line("At what repeat volume? Enter percent (0 to 1): ");
    user_input = read_line();
    music2 = to_double(user_input);

    
    write_line("Playing " + name + " at " + to_string(music1) + " volume for " + to_string(seconds) + " seconds...");
    play_sound_effect(name, music2);
    delay(seconds * 1000);
    stop_sound_effect(name);
    write_line("Stopping music");

    
    write_line("Playing " + name + " at " + to_string(music2) + " volume for " + to_string(seconds) + " seconds...");
    play_sound_effect(name, music2);
    delay(seconds * 1000);
    stop_sound_effect(name);
    write_line("Stopping music");

    
    
}