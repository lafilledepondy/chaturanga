#pragma once

#include <string>
#include <sstream>

class Position {
    private:
        // ----------------------------------------------------------------------------
        // private attribute
        // ----------------------------------------------------------------------------    
        const int _x;
        const int _y;

    public:
        // ----------------------------------------------------------------------------
        // constructors
        // ----------------------------------------------------------------------------    
        // Position(int x, int y);
        // Position(Position p, int dx, int dy);
        // Position(std::string str);

        Position(int x, int y) : _x(x), _y(y) {}
        Position(Position p, int dx, int dy) : _x(p._x + dx), _y(p._y + dy) {}
        Position(std::string str) : _x(str[0] - 'A' + 1), _y(str[1] - '0') {}

        // ----------------------------------------------------------------------------
        // methods
        // ----------------------------------------------------------------------------        
        std::string toString() const;
};