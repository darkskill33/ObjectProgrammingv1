#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Mylib.h"

bool isnumber(string str) ///check if string is number;
{
    for(int i = 0; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

TEST_CASE( "Checks if isnumber gives correct output", "[not number]" ) {
    REQUIRE( isnumber("tree") == 0);
    REQUIRE( isnumber("123") == 1);
    REQUIRE( isnumber("1fcde") == 0);

}