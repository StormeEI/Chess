#include "main.h"

void initChessWindow() { 
    int boardSize = 900;
    int tileSize = 100;
    int border = 50;
    
    // board start
    int centerX = screenWidth/2 - boardSize/2;
    int centerY = screenHeight/2 - boardSize/2;

    // initialize all parts
    Tile board[64];
    Piece pieces[32];
    Texture2D pieceTextures[12];
    initPieces(pieces, board, centerX + border, centerY + border, tileSize);

    /* for checking pieces positions
    for (int i = 0; i < 32; i++) {
        printf("Piece: %d %c %s \n", i, pieces[i].pieceType,(pieces[i].tile)->tile);
    }
    */
    
    InitWindow(screenWidth, screenHeight, "Chess Board Window");
    loadPieceTextures(pieceTextures);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        // draws outer border
        DrawRectangleLinesEx((Rectangle){ centerX, centerY, boardSize, boardSize }, border, BROWN); // beige maybe

        int tileStartX = centerX + border;
        int tileStartY = centerY + border;

        // for now all this does is draw the board
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {

                int x = tileStartX + row * tileSize;
                int y = tileStartY + col * tileSize;

                // chooses color based on row
                bool light = (row + col) % 2 == 0;
                DrawRectangle(x, y, tileSize, tileSize, light ? WHITE : BROWN);
            }
        }

        for (int i = 0; i < 64; i++) {
            if (board[i].piece == NULL) {
                continue;
            } else {
                switch (board[i].piece->pieceType) {
                    // all white pieces
                    case 'P':
                        DrawTexture(pieceTextures[WHITE_PAWN], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'R':
                        DrawTexture(pieceTextures[WHITE_ROOK], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'N':
                        DrawTexture(pieceTextures[WHITE_KNIGHT], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'B':
                        DrawTexture(pieceTextures[WHITE_BISHOP], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'Q':
                        DrawTexture(pieceTextures[WHITE_QUEEN], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'K':
                        DrawTexture(pieceTextures[WHITE_KING], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;

                    // all black pieces
                    case 'p':
                        DrawTexture(pieceTextures[BLACK_PAWN], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'r':
                        DrawTexture(pieceTextures[BLACK_ROOK], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'n':
                        DrawTexture(pieceTextures[BLACK_KNIGHT], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'b':
                        DrawTexture(pieceTextures[BLACK_BISHOP], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'q':
                        DrawTexture(pieceTextures[BLACK_QUEEN], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                    case 'k':
                        DrawTexture(pieceTextures[BLACK_KING], board[i].positionX, board[i].positionY, board[i].piece->color);
                        break;
                }
            }
        }


        // finish
        EndDrawing();
    }
    unloadPieceTextures(pieceTextures);
    CloseWindow();
}