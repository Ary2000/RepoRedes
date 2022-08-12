#ifndef pieces
#define pieces

#include <stdlib.h>
#include <stdbool.h>

enum pieceType{Pawn, Bishop, Knight, Rook, Queen, King};

typedef struct{
    int id, row, column;
    enum pieceType pieceType;
    bool white;

}piece;

piece* newPieces(int id, int row, int column, enum pieceType pt, bool color){
    piece* p = malloc(sizeof(piece));
    p->id = id;
    p->row = row;
    p->column = column;
    p->pieceType = pt;
    p->white = color;
    return p;
}

#endif