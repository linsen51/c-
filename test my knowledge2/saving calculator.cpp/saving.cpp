#include "splashkit.h"


int main()
{
    string name;
    string title;
    string user_input;
    double total, have, per_week, weeks, left, need_per_week, need_weeks;
    
    
    write_line("What are you saving for? Enter title: ");

    title = read_line();

    write_line("How much do you need to save? Enter dollars: ");
user_input = read_line();
    total = to_double(user_input);

    write_line("How long before the purchase? Enter weeks: ");
user_input = read_line();
    weeks = to_integer(user_input);


    write_line("How much do you have already? Enter dollars: ");
user_input = read_line();
    have = to_double(user_input);

    write_line("How much can you save each week? Enter dollars: ");
user_input = read_line();
    per_week = to_double(user_input);

    
    left = total - have;
    need_per_week = left / weeks;
    need_weeks = left / per_week;

    
    write_line("For the " + title + ", you need to save " + to_string((double)need_per_week) + " dollars a week");
    write_line("Based on current savings you will need " + to_string(need_weeks) + " weeks to save $" + to_string((double)total));

    return 0;
}

