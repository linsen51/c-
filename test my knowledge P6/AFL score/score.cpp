#include "splashkit.h"

void draw_heading_line(int width = 20)
{
    for(int i = 0; i < width; i++)
    {
        write("-");
    }
    write_line();
}


void draw_title(string title, int width = 20)
{
    
    draw_heading_line(width);
    write_line(title);
    draw_heading_line(width);
    
}

bool read_boolean(string prompt)
{
    string input;
    write(prompt);
    input = read_line();

    return(input == "y" || input == "Y");
}

int read_integer_range(string prompt, int min, int max)
{
    int value;

    do
    {
        
        write(prompt);
        value = to_integer(read_line());
    }
    while (value < min || value > max);

    return value;
}


int main()
{
    string run_again;
    bool again = false;

    do
    {
    draw_title("AFL Score Clac", 20);
    write("Enter team name: ");
    string team = read_line();

    int goals = read_integer_range("Enter goals: ", 0, 100);
    int behinds = read_integer_range("Enter behinds: ", 0, 100);

    int total = goals * 6 + behinds;

    write_line(team + " Score:");
    write_line(to_string(goals) + " goals, " + to_string(behinds) + " behinds = " + to_string(total));


    
    int option;

do {
    string user_input;
    
    write_line("1: Update goals");
    write_line("2: Update behinds");
    write_line("3: Print details");
    write_line("4: Quit");
   
    write("Enter option: ");
    user_input = read_line();
    option = to_integer(user_input);
    
     if (option < 1 || option > 4) 
     {
        write_line("Please enter a number between 1 and 4");
        continue;
     }
     
    switch(option)
    {
        case 1:
            goals = read_integer_range("Enter new goals: ", 0, 100);
            total = goals * 6 + behinds;
            write_line(team + " Score:");
            write_line(to_string(goals) + " goals, " + to_string(behinds) + " behinds = " + to_string(total));
            break;

        case 2:
            behinds = read_integer_range("Enter new behinds: ", 0, 100);
            total = goals * 6 + behinds;
            write_line(team + " Score:");
            write_line(to_string(goals) + " goals, " + to_string(behinds) + " behinds = " + to_string(total));
            break;

        case 3:
            write_line(team + " Score:");
            write_line(to_string(goals) + " goals, " + to_string(behinds) + " behinds = " + to_string(goals * 6 + behinds));
            break;

        case 4:
            write_line("Quit");
            break;
    }



}while (option != 4);

    again = read_boolean("Run again?(y/n):");
    
}while(again);
    
return 0;
}