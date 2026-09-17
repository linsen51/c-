#include "shop.h"
#include "utilities.h"

cheese_data new_cheese(string name, double weight, int price_per_kg)
{
    cheese_data cheese;
    cheese.name = name;
    cheese.weight = weight;
    cheese.price_per_kg = price_per_kg;

    return cheese;
}

void add_cheese(cheese_list &cheeses)
{
    string name;
    double weight;
    int price;

    name = read_string("Enter cheese name: ");
    weight = read_double("Enter weight in stock (kg): ");
    price = read_integer("Enter price per kg (cents): ");

    add(cheeses, new_cheese(name, weight, price));
}

void print_cheeses(const cheese_list &cheeses)
{
    write_line("");
    write_line("===================================");
    write_line("Cheese stock list:");
    write_line("===================================");

    for(int i = 0; i < length(cheeses); i++)
    {
        write_line( cheese_to_string(cheeses[i], true));
    }

    write_line("===================================");
}

int select_cheese(const cheese_list &cheeses)
{
    write_line("");
    write_line("===================================");
    write_line("Select Cheese:");
    write_line("===================================");

    write_line("0: Select none");

    for(int i = 0; i < length(cheeses); i++)
    {
        write_line(std::format("{}: {}", i + 1,cheese_to_string(cheeses[i], true)));
    }

    return read_integer(std::format("Select cheese (0 - {}): ", length(cheeses)));
}

void edit_cheese(cheese_data &cheese)
{
    write_line("");
    write_line("===================================");
    write_line("Edit Cheese:");
    write_line("===================================");

    write_line( "Editing cheese: " + cheese_to_string(cheese, true));

    if(read_integer("Do you want to edit the name? (1 for yes, 0 for no): "))
    {
        cheese.name = read_string("Enter new name: ");
    }

    if(read_integer("Do you want to edit the weight? (1 for yes, 0 for no): "))
    {
        cheese.weight = read_double("Enter new weight in stock (kg): ");
    }

    if(read_integer("Do you want to edit the price? (1 for yes, 0 for no): "))
    {
        cheese.price_per_kg =
            read_integer("Enter new price per kg (cents): ");
    }
}

string cheese_to_string(const cheese_data &cheese, bool full_details)
{
    if(full_details)
    {
        return std::format(
            "{}: {:.2f} kg, ${:.2f}",
            cheese.name,
            cheese.weight,
            cheese.price_per_kg / 100.0
        );
    }

    return cheese.name;
}