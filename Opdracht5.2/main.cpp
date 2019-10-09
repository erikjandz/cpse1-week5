//Author is Erik de Zeeuw
#include "set.hpp"
#include <iostream>
#include "catch.hpp"
#define CATCH_CONFIG_MAIN

TEST_CASE( "int, 6" ){
    set<int, 6> test;
    test.add(5);
    test.add(5);
    test.add(10);
    test.add(6);
    test.add(7);
    test.add(3);
    test.add(4);
    std::stringstream a;
    a << test;
    REQUIRE(a.str() == "5\n10\n6\n7\n3\n4\n");
}

TEST_CASE( "char, 4" ){
    set<char, 4> test;
    test.add('h');
    test.add('g');
    test.add('r');
    test.add('c');
    std::stringstream b;
    b << test;
    REQUIRE(b.str() == "h\ng\nr\nc\n");
}