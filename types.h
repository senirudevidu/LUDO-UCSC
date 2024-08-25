#ifndef TYPES_H
#define TYPES_H

#define BASE -1
#define START_X 0

#define TOTAL_PLAYERS 4
#define TOTAL_PIECES 4

#define TOTAL_CELLS 52
#define HOME_STRAIGHT_SIZE 5
#define TOTAL_RUNNING_CELLS 57
#define LAST_ELEMENT_INDEX 56

// Define a structure for Pieces
typedef struct {
    int position;       // The current position of the piece on the board
                        // -1: in base
                        // 0 to 51: on standard cells (index 0 is the start cell)
                        // 52 to 56: on the home straight
                        // 57: at home
    int isInPlay;      // 1 if the piece is active on the board, 0 if in base or at home
} Piece;

typedef struct {
    Piece pieces[4];    // Array of 4 pieces for each player
    char colour;
    int index;         // The player's color (R, Y, G, B)
} Player;

#endif // TYPES_H
