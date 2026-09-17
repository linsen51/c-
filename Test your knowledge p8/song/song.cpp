#include "splashkit.h"
#include "utilities.h"
#include "song.hpp"

struct song_data
{
    string name;
    string id;
    string path;
    bool loved;
    int times_played;
};

struct music_player_data
{
    dynamic_array<song_data> songs;
    int next_id = 0;
};

song_data read_song();
void add_song(music_player_data &player);
void list_songs(const music_player_data &player);
int find_song(const music_player_data &player);
void play_song(music_player_data &player);
void update_song(music_player_data &player);
void print_status(const music_player_data &player);

enum menu_option
{
    ADD_SONG = 1,
    UPDATE_SONG = 2,
    PLAY_SONG = 3,
    PAUSE_RESUME = 4,
    PRINT_STATUS = 5,
    LIST_SONG = 6,
    QUIT = 7,
};


void print_menu()
{
    write_line("=== Music Player ===");
    write_line("1. Add song");
    write_line("2. Update song");
    write_line("3. Play song");
    write_line("4. Pause/Resume");
    write_line("5. Status");
    write_line("6. List songs");
    write_line("7. Quit");
}



void add_song(music_player_data &player)
{
    song_data song;

    song.name = read_string("Song nmae: ");
    song.path = read_string("File path: ");
    song.loved = read_boolean("Loved (true/false): ");
    song.times_played = 0;

    song.id = "song-" + to_string(player.next_id);
    player.next_id++;

    player.songs.add(song);

    load_music(song.id, song.path);

    write_line("Loaded " + song.id + "from" + song.path);

}

void list_songs(const music_player_data &player)
{
    for (int i = 0; i < player.songs.length(); i++)
    {
        write_line(to_string(i + 1) + "." + player.songs[i].name);
    }
}

const int NO_CHOICE = -1;
int find_song(const music_player_data &player)
{
    if (player.songs.length() == 0)
    {
        write_line("No songs available.");
        return NO_CHOICE;
    }

    string keyword = read_string("Search: ");
    bool found = false;

    for (int i = 0; i < player.songs.length(); i++)
    {
        if (contains(player.songs[i].name, keyword))
        {
            write_line(to_string(i + 1) + "." + player.songs[i].name);
            found = true;
        }
    }

    if (!found)
    {
        write_line("No match.");
        return NO_CHOICE;
    }

    int index = read_integer("Choose: ") - 1;

    if (index < 0 || index >= player.songs.length())
    {
        return NO_CHOICE;
    }
    
    return index;
}

void play_song(music_player_data &player)
{
    int index = find_song(player);
    if (index == NO_CHOICE) 
    {
        return;
    }
    player.songs[index].times_played++;

    play_music(player.songs[index].id);

    write_line("Playing: " + player.songs[index].name);
}

void update_song(music_player_data &player)
{
    int index = find_song(player);
    if (index == NO_CHOICE) 
    {
        return;
    }
    int choice;

    do
    {
        write_line("1. Update name");
        write_line("2. Toggle loved");
        write_line("3. Reset play count");
        write_line("4. Delete song");
        write_line("5. Quit");

        choice = read_integer("Choice: ");

      switch(choice)
    { 
        case 1: 
        player.songs[index].name = read_string("New name: "); 
        break; 

        case 2: 
        player.songs[index].loved = !player.songs[index].loved;
        break; 
         
        case 3:
        player.songs[index].times_played = 0;
        break;
           
        case 4:
        player.songs.remove(index);
        write_line("Deleted.");
        return;

    }
    } while (choice != 5);
}

void print_status(const music_player_data &player)
{
    int total_played = 0;
    int loved_count = 0;

    for (int i = 0; i < player.songs.length(); i++)
    {
        total_played = total_played + player.songs[i].times_played;

        if (player.songs[i].loved)
        {
            loved_count++;
        }
        
    }

    write_line("Songs: " + to_string(player.songs.length()));
    write_line("Total plays: " + to_string(total_played));
    write_line("Loved songs: " + to_string(loved_count));
}

int main()
{
    music_player_data player;

    menu_option option;

    do
    {
        print_menu();
        option = (menu_option)read_integer("Choose: ");

        switch(option)
        {
            case ADD_SONG:
                add_song(player);
                break;

            case UPDATE_SONG:
                update_song(player);
                break;

            case PLAY_SONG:
                play_song(player);
                break;

            case PAUSE_RESUME:
                pause_music();
                break;

            case PRINT_STATUS:
                print_status(player);
                break;

            case LIST_SONG:
                list_songs(player);
                break;

            case QUIT:
                break;
        }
    } while (option != QUIT);
    return 0;
}
