#include "board.h"
#include <iostream>
using namespace std;
// --- Helper implementations ---

int row(int sq)               { return sq / 8; }
int col(int sq)               { return sq % 8; }
int sq(int r, int c)          { return r * 8 + c; }
bool in_bounds(int r, int c)  { return r >= 0 && r < 8 && c >= 0 && c < 8; }

int piece_color(int piece) {
    if (piece > 0) return WHITE;
    if (piece < 0) return BLACK;
    return 0;
}

// --- Starting position ---

Board::Board() {
    // Clear everything
    for (int i = 0; i < 64; i++) squares[i] = EMPTY;

    side_to_move    = WHITE;
    castling_rights = CASTLE_WHITE_KINGSIDE | CASTLE_WHITE_QUEENSIDE |
                      CASTLE_BLACK_KINGSIDE | CASTLE_BLACK_QUEENSIDE;
    en_passant_sq   = -1;
    halfmove_clock  = 0;
    fullmove_number = 1;

    // White pieces (rank 1, row 0)
    squares[sq(0,0)] =  ROOK;
    squares[sq(0,1)] =  KNIGHT;
    squares[sq(0,2)] =  BISHOP;
    squares[sq(0,3)] =  QUEEN;
    squares[sq(0,4)] =  KING;
    squares[sq(0,5)] =  BISHOP;
    squares[sq(0,6)] =  KNIGHT;
    squares[sq(0,7)] =  ROOK;

    // White pawns (rank 2, row 1)
    for (int c = 0; c < 8; c++)
        squares[sq(1,c)] = PAWN;

    // Black pawns (rank 7, row 6)
    for (int c = 0; c < 8; c++)
        squares[sq(6,c)] = -PAWN;

    // Black pieces (rank 8, row 7)
    squares[sq(7,0)] = -ROOK;
    squares[sq(7,1)] = -KNIGHT;
    squares[sq(7,2)] = -BISHOP;
    squares[sq(7,3)] = -QUEEN;
    squares[sq(7,4)] = -KING;
    squares[sq(7,5)] = -BISHOP;
    squares[sq(7,6)] = -KNIGHT;
    squares[sq(7,7)] = -ROOK;
}

// --- Print ---

void print_board(const Board& b) {
    // index 0 unused, 1=P, 2=N, 3=B, 4=R, 5=Q, 6=K
    string white_symbols = " PNBRQK";
    string black_symbols = " pnbrqk";

    cout << "\n  a b c d e f g h\n";
    for (int r = 7; r >= 0; r--) {
        cout << (r + 1) << " ";
        for (int c = 0; c < 8; c++) {
            int piece = b.squares[sq(r, c)];
            if (piece == 0)
                cout << ". ";
            else if (piece > 0)
                cout << white_symbols[piece] << " ";
            else
                cout << black_symbols[-piece] << " ";
        }
        cout << "\n";
    }
}