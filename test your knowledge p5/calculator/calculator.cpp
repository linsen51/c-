#include "splashkit.h"

int main()
{
    
    int count = 0;          
    double total = 0.0;   
    double value;           
    string user_input, again;      

   
    write_line("Welcome to the simple stats calculator!");

   
    do
    {
        write_line("Enter value: ");
        user_input = read_line();
        
        while (!is_double(user_input))
        {
        write("Please enter a number: ");
        user_input = read_line();
        }
        
        value = to_double(user_input);

       
        total = total + value;
        count++;

        
        write_line("Count: " + to_string(count));
        write_line("Total: " + to_string(total));
        write_line("Average: " + to_string(total / count));

        
        write("Add another value? [y/n]: ");
        again = read_line();

    } while (again == "y");
}