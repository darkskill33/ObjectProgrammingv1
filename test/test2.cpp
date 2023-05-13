#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Mylib.h"

bool lowerthanfive(double x) ///bool for sorting students;
{
    return x < 5;
}

TEST_CASE( "Checks if given number is lower than five", "double values" ) {
    REQUIRE( lowerthanfive(5.1) == 0);
    REQUIRE( lowerthanfive(1.23) == 1);
    REQUIRE( lowerthanfive(6) == 0);

}