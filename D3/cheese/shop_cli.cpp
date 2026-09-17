#include "splashkit.h"
#include "utilities.h"
#include "shop.h"

int main()
{
    cheese_list cheeses;

    int option;

    do
    {
        write_line("");
        write_line("===================================");
        write_line("Main Menu:");
        write_line("===================================");

        write_line("0. Exit");
        write_line("1. Add cheese");
        write_line("2. Edit cheese");
        write_line("3. Print cheese list");

        option = read_integer("Select an option (0-3): ");

        switch(option)
        {
            case 1:
                add_cheese(cheeses);
                break;

            case 2:
            {
                int idx = select_cheese(cheeses);

                if(idx > 0)
                {
                    edit_cheese(
                        cheeses[idx - 1]
                    );
                }
                break;
            }

            case 3:
                print_cheeses(cheeses);
                break;
        }

    } while(option != 0);

    write_line("Exiting...");

    return 0;
}