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
    if (p->white)
    {
        if (newColumn != p->column)
        {
            return false;
        }else if (4 == newRow && p->row == 2)
        {
            return true;
        }else if (p->row + 1 == newRow)
        {
            return true;
        }else{
            return false;
        }
        
        
        
    }else{
        if (newColumn != p->column)
        {
            return false;
        }else if (5 == newRow && p->row == 7)
        {
            return true;
        }else if (p->row - 1 == newRow)
        {
            return true;
        }else{
            return false;
        }
    }
}

bool validateBishopMove(piece *p, int newRow, int newColumn){
    return true;
}

bool validateKnightMove(piece *p, int newRow, int newColumn){
    if (p->column+2 == newColumn && (p->row+1==newRow || p->row-1==newRow))
    {
        return true;
    }else if (p->column-2 == newColumn && (p->row+1==newRow || p->row-1==newRow))
    {
        return true;
    }else if (p->row+2 == newRow && (p->column+1==newColumn || p->column-1==newColumn))
    {
        return true;
    }else if (p->row-2 == newRow && (p->column+1==newColumn || p->column-1==newColumn))
    {
        return true;
    }else{
        return false;
    }
}

bool validateRookMove(piece *p, int newRow, int newColumn){
    return p->column != newColumn && p->row == newRow || p->column == newColumn && p->row != newRow;
}

bool validateKingMove(piece *p, int newRow, int newColumn){
    int column = p->column;
    int row = p->row;
    if(column == newColumn && row == newRow){
        return false;
    }
    column = column-newColumn;
    row = row-newRow;
    return column<2&&row<2&&-2<column&&-2<row;
}

#endif