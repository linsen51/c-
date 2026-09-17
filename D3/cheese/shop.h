#ifndef SHOP_H
#define SHOP_H

#include <splashkit.h>
#include <splashkit-arrays.h>
#include <string>
#include <format>

using std::string;

struct cheese_data
{
    string name;
    double weight;
    int price_per_kg;
};

typedef dynamic_array<cheese_data> cheese_list;

cheese_data new_cheese(
    string name = "",
    double weight = 0.0,
    int price_per_kg = 0
);

string cheese_to_string(
    const cheese_data &cheese,
    bool full_details = false
);

void add_cheese(cheese_list &cheeses);

void print_cheeses(const cheese_list &cheeses);

int select_cheese(const cheese_list &cheeses);

void edit_cheese(cheese_data &cheese);

#endif