//Author is Erik de Zeeuw
#include "set.hpp"
#include <iostream>
#include "catch.hpp"
#define CATCH_CONFIG_MAIN


TEST_CASE( "max" ){
    set<int, 6> test;
    test.add(5);
    test.add(4);
    test.add(9);
    test.add(14);
    test.add(-2);
    test.add(8);
    REQUIRE(test.max() == 14);
}

