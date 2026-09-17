#include "splashkit.h"
#include "utilities.h"

class account
{
    private:
        string username;
        string password;

    public:
        void set_account(string user, string pass)
        {
            username = user;
            password = pass;
            write_line("- Account set.");
        }

        bool login(string input_password, string input_username)
        {

            if (input_username == username && input_password == password)
            {
                write_line("- Login successful");
                return true;
            }
            else
            {
                write_line("- Login failed");
                return false;
            }
        }

        

        void change_password(string current, string new_password)
        {

            if (current != password)
            {
                write_line("- Failed to change password - invalid password");
            }
            else if (new_password == password)
            {
                write_line("Failed to change password - password reuse");
            }
            else if (current == password)
            {
                password = new_password;
                write_line("- Password changed");
            }
        }
};


enum menu_option
        {
            SET_ACCOUNT = 1,
            TEST_LOGIN = 2,
            CHANGE_PASSWORD = 3,
            QUIT = 4,
        };


int main()
{
    account acc;
    int option;

    string user = read_string("Username: ");
    string pass = read_string("Password: ");
    
    acc.set_account(user, pass);


    do
    {
        write_line("\n1: Set account");
        write_line("2: Test login");
        write_line("3: Change password");
        write_line("4: Quit");

        option = read_integer("> ");

        switch(option)
        {
            case SET_ACCOUNT:
                {
                string user = read_string("Username: ");
                string pass = read_string("Password: ");
                acc.set_account(user, pass);
                break;
                }
            case TEST_LOGIN:
                {
                string input_username = read_string("Username: ");
                string input_password = read_string("Password");
                acc.login(input_password, input_username);
                break;
                }
            case CHANGE_PASSWORD:
                {
                string current = read_string("Current password: ");
                string new_password = read_string("New password: ");
                acc.change_password(current, new_password);
                break;
                }
            case QUIT:
                break;
            default:
                write_line("Invalied option");
        }

    } while (option != QUIT);

    return 0;
}