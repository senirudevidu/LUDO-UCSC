
#define TYPES_H



#define BASE -1
#define START_X 0


// Define a structure for piece.
typedef struct {
    char name[3];  // Name of the piece (e.g., "R1", "G2")
    int position;  // Current position of the piece on the board
    int isInPlay;  // Flag indicating whether the piece is in play (1 = yes, 0 = no)
} Piece;


