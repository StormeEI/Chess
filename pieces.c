#include "main.h"

void initPieces(Piece* pieces, Tile* board) {
    // creates all the spaces for board
    for (int rank = '1'; rank <= '8'; rank++) {
        int rankIndex = rank - '1';
        for (int file = 'a'; file <='h'; file++) {
            // gives us our index for the board[]
            int fileIndex = file - 'a';
            int index = rankIndex * 8 + fileIndex;

            // gives us our string for strcpy
            char tile[3];
            tile[0] = file;
            tile[1] = rank;
            tile[2] = '\0';
            strcpy(board[index].tile, tile);
            board[index].piece = NULL;
        }
    }
}