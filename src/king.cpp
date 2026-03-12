#include "king.hpp"

King::King(bool isBlack):Piece(isBlack, "king") {}

bool King::isValidMove(const Position &start_pos, const Position &end_pos, 
    bool isCapture, Plateau* board) const {
    // TODO
    return true;
}