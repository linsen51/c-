#include "utilities.h"
#include "splashkit.h"

string read_string(string prompt)
{
  write(prompt);
  return read_line();
}

int read_integer(string prompt)
{
  string line = read_string(prompt);
  while (!is_integer(line))
  {
    write_line("Please enter a whole number.");
    line = read_string(prompt);
  }
  return to_integer(line);
}

double read_double(string prompt)
{
    write(prompt);
    return to_double(read_line());
}
bool read_boolean(string prompt)
{
    int value = read_integer(prompt + " (1=true, 0=false): ");
    return value == 1;
}