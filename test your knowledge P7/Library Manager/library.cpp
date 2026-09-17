#include "utilities.h"
#include "splashkit.h"


enum Menu
{
    ENTER_BOOK_DETAILS = 1,
    PRINT_BOOK,
    QUIT,

};

string to_string(Menu M)
{
    switch (M)
    {
        case ENTER_BOOK_DETAILS:
        return"Enter_book_details:";

        case PRINT_BOOK:
        return"Print_book:";

        case QUIT:
        return"Quit:";
    }
}
struct book_data
{
    string title;
    string location;
    int pages;
};



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

void enter_book(book_data & book)
{
    string user_input;
    write_line("Enter the name of the book:");
    user_input = read_line();
    book.title = user_input;
    write_line("Enter book location:");
    user_input = read_line();
    book.location = user_input;
    book.pages = read_integer_range("Enter number of pages (1-1000):", 1, 1000);
}

void print_book(book_data book)
{
    write_line("Book details:");
        write_line("Title: " + book.title);
        write_line("Location: " + book.location);
        write_line("Pages: " + to_string(book.pages));
}

int main()
{
    book_data book;
    int option;

    enter_book(book);
    do
    {
        string user_input;

        write_line("Menu:");
        write_line("1 - Enter book details");
        write_line("2 - Print book");
        write_line("3 - Quit");

        write("Enter option: ");
    user_input = read_line();
    

     while(!is_double(user_input))
    {
        write("Please enter a number: ");
        user_input = read_line();
    }

    option = to_integer(user_input);

     if (option < 1 || option > 3) 
     {
        write_line("Please enter a number between 1 and 3");
        continue;
     }
     
     switch(option)
     {
        case ENTER_BOOK_DETAILS:
        enter_book(book);
        break;

        case PRINT_BOOK:
        print_book(book);
        break;

        case QUIT:
        break;


     }
        
    }while(option != QUIT);

    return 0;
}