#pragma once

// Pieces: positive = white, negative = black, 0 = empty
const int EMPTY  = 0;
const int PAWN   = 1;
const int KNIGHT = 2;
const int BISHOP = 3;
const int ROOK   = 4;
const int QUEEN  = 5;
const int KING   = 6;

// Colors
const int WHITE  =  1;
const int BLACK  = -1;

// Castling rights (used as bitmask)
const int CASTLE_WHITE_KINGSIDE  = 1;
const int CASTLE_WHITE_QUEENSIDE = 2;
const int CASTLE_BLACK_KINGSIDE  = 4;
const int CASTLE_BLACK_QUEENSIDE = 8;