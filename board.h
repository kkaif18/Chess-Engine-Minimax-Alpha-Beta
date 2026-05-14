#pragma once
#include "constants.h"

struct Move {
    int from;            // square index 0–63  (from = row*8 + col)
    int to;              // square index 0–63
    int captured;        // piece that was on `to` (0 if empty)
    int promotion;       // piece to promote to (0 if not a promotion)
    bool is_castling;
    bool is_en_passant;

    Move() : from(0), to(0), captured(0), promotion(0),
             is_castling(false), is_en_passant(false) {}
};

struct Board {
    int squares[64];     // the board, index = row*8 + col
    int side_to_move;    // WHITE or BLACK
    int castling_rights; // bitmask of the 4 CASTLE_* constants
    int en_passant_sq;   // index of valid en passant target, or -1
    int halfmove_clock;  // for 50-move rule
    int fullmove_number;

    Board();             // sets up starting position
};

// Helpers
int  row(int sq);                    // sq / 8
int  col(int sq);                    // sq % 8
int  sq(int row, int col);           // row*8 + col
bool in_bounds(int row, int col);
int  piece_color(int piece);         // returns WHITE, BLACK, or 0

void print_board(const Board& b);