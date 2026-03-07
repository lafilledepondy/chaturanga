#include <stdio.h>
#include <assert.h>

#include "position.hpp"

void test_Position() {
    std::cout << "--- Test Valid Position ---\n";

    Position p1(1, 5); 
    Position p2(p1, 1, 1);
    Position p3("A1");

    assert(p1.to_string() == "A5");
    assert(p2.to_string() == "B6");
    assert(p3.to_string() == "A1");

    std::cout << "\n" << std:endl;
    std::cout << "--- Test Not Valid Position(x,y) ---\n";

    try {
        Position p1(0, 4);
        assert(false);
    } catch (const std::invalid_argument&) {}

    try {
        Position p2(4, 0);
        assert(false);
    } catch (const std::invalid_argument&) {}

    try {
        Position p3(3, 9);
        assert(false);
    } catch (const std::invalid_argument&) {}    

    try {
        Position p4(15, 3);
        assert(false);
    } catch (const std::invalid_argument&) {}      

    std::cout << "\n" << std:endl;
    std::cout << "--- Test Not Valid Position(p,dx,dy) ---\n";    
    
    try {
        Position p(-1, 1, 4);
        assert(false);
    } catch (const std::invalid_argument& e) {}

    try {
        Position p(10, 1, 4);
        assert(false);
    } catch (const std::invalid_argument& e) {}    
    
    try {
        Position p(2, 1, 8);
        assert(false);
    } catch (const std::invalid_argument& e) {}    

    try {
        Position p(-1, 5, 1);
        assert(false);
    } catch (const std::invalid_argument& e) {}      

    std::cout << "\n" << std:endl;
    std::cout << "--- Test Not Valid Position(str) ---\n";    

    try {
        Position p("A810");
        assert(false);
    } catch (const std::invalid_argument& e) {}

    try {
        Position p("a1");
        assert(false);
    } catch (const std::invalid_argument& e) {}    
    
    try {
        Positionp p("z1");
        assert(false);
    } catch (const std::invalid_argument& e) {}    

    try {
        Positionp p("Z1");
        assert(false);
    } catch (const std::invalid_argument& e) {}     

    try {
        Position p("A9");
        assert(false);
    } catch (const std::invalid_argument& e) {}    

    try {
        Position p("A0");
        assert(false);
    } catch (const std::invalid_argument& e) {}       

    std::cout << "Test Not Valid Position : OK\n\n";
}