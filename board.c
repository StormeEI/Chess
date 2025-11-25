#include "main.h"

void initChessWindow() {
    int boardSize = 900;
    int tileSize = 100;
    int border = 50;

    // where our board will be built
    int centerX = screenWidth/2 - boardSize/2;
    int centerY = screenHeight/2 - boardSize/2;

    // initialize all parts
    Tile board[64];
    Piece pieces[32];
    initPieces(pieces, board);

    /* for checking pieces positions
    for (int i = 0; i < 32; i++) {
        printf("Piece: %d %c %s \n", i, pieces[i].pieceType,(pieces[i].tile)->tile);
    }
    */
    
    InitWindow(screenWidth, screenHeight, "Chess Board Window");


    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        // draws outer border
        DrawRectangleLinesEx((Rectangle){ centerX, centerY, boardSize, boardSize }, border, BEIGE);

        int tileStartX = centerX + border;
        int tileStartY = centerY + border;

        // for now all this does is draw the board
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {

                int x = tileStartX + row * tileSize;
                int y = tileStartY + col * tileSize;

                // chooses color based on row
                bool light = (row + col) % 2 == 0;
                DrawRectangle(x, y, tileSize, tileSize, light ? WHITE : BLACK);
            }
        }
        EndDrawing();
    }
    CloseWindow();
}