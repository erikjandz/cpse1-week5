#include "set.hpp"
#include <iostream>
#include "catch.hpp"
#define CATCH_CONFIG_MAIN


TEST_CASE( "max" ){
    set<char, 3> test;
    test.add('h');
    test.add('o');
    test.add('i');
    REQUIRE(test.max() == 'o');
}

