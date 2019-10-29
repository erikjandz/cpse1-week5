//Author is Erik de Zeeuw
#include "set.hpp"
#include <array>
#include <iostream>
#include "catch.hpp"
#define CATCH_CONFIG_MAIN


TEST_CASE( "max" ){
    set<std::array<char, 3>, 10> test;
    test.add({'z','z','z'});
    test.add({'y','e','s'});
    test.add({'h','o','i'});
    REQUIRE(test.max() == test.get(0));
}
