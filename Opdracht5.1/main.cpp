//Author is Erik de Zeeuw
#include <iostream>
#include "set.hpp"
#include "catch.hpp"
#define CATCH_CONFIG_MAIN

TEST_CASE( "add, unique values and cout" ){
    set test;
    test.add(5);
    test.add(5);
    test.add(10);
    test.add(6);
    test.add(7);
    test.add(3);
    std::stringstream a;
    a << test;
    REQUIRE(a.str() == "5\n10\n6\n7\n3\n");
}

TEST_CASE( "add more than 10" ){
    set test;
    test.add(5);
    test.add(10);
    test.add(6);
    test.add(7);
    test.add(3);
    test.add(4);
    test.add(8);
    test.add(1);
    test.add(2);
    test.add(9);
    test.add(11);
    test.add(12);
    std::stringstream b;
    b << test;
    REQUIRE(b.str() == "5\n10\n6\n7\n3\n4\n8\n1\n2\n9\n");
}

TEST_CASE( "remove and contain" ){
    set test;
    test.add(5);
    test.add(10);
    test.add(6);
    test.add(7);
    test.add(3);
    test.remove(10);
    test.remove(5);
    test.remove(3);
    std::stringstream c;
    c << test;
    REQUIRE(test.contains(6));
    REQUIRE(test.contains(7));
    REQUIRE(!test.contains(8));
    REQUIRE(c.str() == "6\n7\n");
}
