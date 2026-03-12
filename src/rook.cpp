#include "rook.hpp"

Rook::Rook(bool isBlack):Piece(isBlack, "rook") {}

bool Rook::isValidMove(const Position &start_pos, const Position &end_pos, 
    bool isCapture, Plateau* board) const {
    // TODO
    return true;
}