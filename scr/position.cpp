// ==============================================================================
// POSITION : position in the checkerboard. Contain x and y.
// ==============================================================================

#include "position.hpp"

Position::Position(int x, int y) {
    if (x<1 || x>8) 
        throw std::invalid_argument("Position::Position(x,y) - x outside checkerboard.");

    if (y<1 || y>8) 
        throw std::invalid_argument("Position::Position(x,y) - y outside checkerboard.");

    this->_x = x;
    this->_y = y;
}

Position::Position(Position p, int dx, int dy) {
    if ((p._x + dx)<1 || (p._x + dx)>8) 
        throw std::invalid_argument("Position::Position(p,dx,dy) - x outside checkerboard.");
  
    if ((p._y + dy)<1 || (p._y + dy)>8) 
        throw std::invalid_argument("Position::Position(p,dx,dy) - y outside checkerboard.");

    this->_x = p._x + dx;
    this->_y = p._y + dy;
}

Position::Position(std::string str) {
    if (str.size() != 2) 
        throw std::invalid_argument("Position::Position(str) - invalid format.");
    
    char col = str[0];         
    char row = str[1];

    if (col<'A' || col>'H') 
        throw std::invalid_argument("Position::Position(str) - x outside checkerboard.");

    if (row<'1' || col>'8') 
        throw std::invalid_argument("Position::Position(str) - y outside checkerboard.");   

    this->_x = col - 'A' + 1;
    this->_y = row - '0';
}

std::string Position::toString() const {
    std::ostringstream oss;
    oss << "[";
    oss << char(this->_x + 'A' - 1);
    oss << std::to_string(this->_y);
    oss << "]";
    return oss.str();
}