#include "splashkit.h"
#include "dynamic_array.hpp"

int main()
{
    dynamic_array<int> arr;

    write_line("Adding values... ");

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    write_line("\nArray values: ");
    arr.print();

    write_line("");
    arr.print_capacity();

    write_line("\nRemoving index 1...");

    arr.remove(1);

    write_line("\nUpadated array: ");
    arr.print();

    write_line("");
    arr.print_capacity();

    return 0;
}