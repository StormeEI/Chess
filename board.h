#ifndef BOARD_H_
#define BOARD_H_

#include <stdlib.h>

typedef struct _LIST {
    char file;
    char rank;
    struct _LIST* prev;
    struct _LIST* next;
} List;

typedef struct _PIECE {
    char pieceType;
    Color color;
    List* position;
} Piece;

void chessWindow();
void piecePlacement();
// void updateWindow();

#endif // BOARD_H_