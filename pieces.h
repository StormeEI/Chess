#ifndef PIECES_H_
#define PIECES_H_

// when a piece moves well need to deal with this
typedef struct _TILE {
    char tile[3];
    int positionX;
    int positionY;
    struct _PIECE* piece;
} Tile;

typedef struct _PIECE {
    char pieceType;
    Color color;
    Tile* tile;
} Piece;

typedef enum {
    WHITE_PAWN, WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP,
    WHITE_QUEEN, WHITE_KING,
    BLACK_PAWN, BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP,
    BLACK_QUEEN, BLACK_KING
} PieceType;

void initPieces(Piece* pieces, Tile* board, int startX, int startY, int tileSize);
int boardIndex(char file, char rank);
void loadPieceTextures(Texture2D* pieceTextures);
void unloadPieceTextures(Texture2D* pieceTextures);

#endif // PIECES_H_