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

bool movePiece(piece *p, int newRow, int newColumn){
    enum pieceType pt = p->pieceType;
    bool valid = false;
    switch (pt)
    {
    case Bishop:
        valid = validateBishopMove(p, newRow, newColumn);
        break;
    case Knight:
        valid = validateKnightMove(p, newRow, newColumn);
        break;
    case Rook:
        valid = validateRookMove(p, newRow, newColumn);
        break;
    case Queen:
        valid = validateBishopMove(p, newRow, newColumn) || validateRookMove(p, newRow, newColumn);
        break;
    case King:
        valid = validateKingMove(p, newRow, newColumn);
        break;
    default:
        valid = validatePawnMove(p, newRow, newColumn);
        break;
    }
    return true;
}

bool validatePawnMove(piece *p, int newRow, int newColumn){
    return true;
}

bool validateBishopMove(piece *p, int newRow, int newColumn){
    return true;
}

bool validateKnightMove(piece *p, int newRow, int newColumn){
    return true;
}

bool validateRookMove(piece *p, int newRow, int newColumn){
    return true;
}

bool validateKingMove(piece *p, int newRow, int newColumn){
    return true;
}

#endif