#include "main.h"

void initPieces(Piece* pieces, Tile* board) {
    // creates all the spaces for board
    for (int rank = '1'; rank <= '8'; rank++) {
        for (int file = 'a'; file <='h'; file++) {
            // gives us our index for the board[]
            int index = boardIndex(file, rank);

            // gives us our string for strcpy
            char tile[3] = {file, rank, '\0'};

            strcpy(board[index].tile, tile);
            board[index].piece = NULL;
        }
    }

    // initializes all colors
    for (int i = 0; i < 32; i++) {
        if (i < 16) {
            pieces[i].color = WHITE;
        } else {
            pieces[i].color = BLACK;
        }
    }

    // some white pieces
    pieces[0].pieceType = 'r';
    pieces[1].pieceType = 'n';
    pieces[2].pieceType = 'b';
    pieces[3].pieceType = 'q';
    pieces[4].pieceType = 'k';
    pieces[5].pieceType = 'b';
    pieces[6].pieceType = 'n';
    pieces[7].pieceType = 'r';

    // white pawns
    for (int i = 8; i < 16; i++) {
        pieces[i].pieceType = 'p';
    }

    // black pawns
    for (int i = 16; i < 24; i++) {
        pieces[i].pieceType = 'p';
    }
    
    // other black pieces
    pieces[24].pieceType = 'r';
    pieces[25].pieceType = 'n';
    pieces[26].pieceType = 'b';
    pieces[27].pieceType = 'q';
    pieces[28].pieceType = 'k';
    pieces[29].pieceType = 'b';
    pieces[30].pieceType = 'n';
    pieces[31].pieceType = 'r';

    for (int i = 0; i < 32; i++) {
        if (i < 16) {
            pieces[i].tile = &board[i];
            board[i].piece = &pieces[i];
        } else {
            pieces[i].tile = &board[i + 32];
            board[i + 32].piece = &pieces[i];
        }
    }
}

int boardIndex(char file, char rank) {
    int fileIndex = file - 'a';
    int rankIndex = rank - '1';
    return rankIndex * 8 + fileIndex;
}