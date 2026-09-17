#include "splashkit.h"

int main()
{
    open_window("Simple Car", 600, 400);
    clear_screen(COLOR_WHITE);

    
    fill_rectangle(COLOR_BLUE, 150, 200, 300, 80);
    
    
    fill_rectangle(COLOR_RED, 250, 160, 100, 40);
    
    
    fill_circle(COLOR_BLACK, 250, 280, 40);
    fill_circle(COLOR_BLACK, 400, 280, 40);

    refresh_screen();
    delay(3000);
    close_all_windows();
    return 0;
}