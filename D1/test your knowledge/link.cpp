#include "splashkit.h"
#include "linked_list.hpp"

int main()
{
    linked_list<int> list;

    node<int> *node1 = list.add_node(10);
    node<int> *node2 = list.add_node(20);

    write_line("Original list: ");
    list.print();

    list.prepend(5);

    write_line("\nAfter prepend: ");
    list.print();

    list.insert_after(node1, 15);

    write_line("\nAfter insert_after: ");
    list.print();

    list.insert_before(node2, 18);

    write_line("\nAfter insert_before: ");
    list.print();

    return 0;
}