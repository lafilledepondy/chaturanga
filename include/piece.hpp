#pragma once

#include "position.hpp"
#include "plateau.hpp"

class Plateau;

class Piece
{
private:
    // ----------------------------------------------------------------------------
    // private attribute
    // ----------------------------------------------------------------------------
    std::string _name; // const TODO
    bool _isBlack;     // const TODO

public:
    // ----------------------------------------------------------------------------
    // constructors
    // ----------------------------------------------------------------------------
    Piece(bool isBlack, std::string name);

    // ----------------------------------------------------------------------------
    // abstract methods
    // ----------------------------------------------------------------------------
    virtual bool isValidMove(const Position &start_pos, const Position &end_pos,
                             bool isCapture, Plateau *board) const = 0;

    // ----------------------------------------------------------------------------
    // methods
    // ----------------------------------------------------------------------------
    bool isBlack() const;
    std::string toString() const;
};