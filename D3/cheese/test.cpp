#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "shop.h"

TEST_CASE("Cheese - Convert cheese data to string")
{
    cheese_data cheese;

    cheese = new_cheese("Cheddar", 1.5, 2000);

    string result = cheese_to_string(cheese, true);
    string expected = "Cheddar: 1.50 kg, $20.00";

    REQUIRE(result == expected);

    result = cheese_to_string(cheese, false);
    expected = "Cheddar";

    REQUIRE(result == expected);
}