#ifndef PIECES_H_
#define PIECES_H_

#include <stdlib.h>

// when a piece moves well need to deal with this
typedef struct _TILE {
    char tile[3];
    struct _PIECE* piece;
} Tile;

typedef struct _PIECE {
    char pieceType;
    Color color;
    Tile* tile;
} Piece;

void initPieces(Piece* pieces, Tile* board);
int boardIndex(char file, char rank);

#endif // PIECES_H_