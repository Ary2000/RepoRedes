#ifndef gameControler
#define gameControler

#include "pieces.c"
#include <stdbool.h>
#include <math.h> //https://www.aprenderaprogramar.com/index.php?option=com_content&view=article&id=909:funciones-matematicas-en-c-redondeo-valor-absoluto-potencia-trigonometricas-raiz-cuadrada-cu00520f&catid=82&Itemid=210

int board[8][8];
piece* chessPieces[32];

bool validatePawnMove(piece *p, int newRow, int newColumn){
    if (p->white)
    {
        if (newColumn != p->column && p->row +1 == newRow)
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
    int tempRow = p->row - newRow;
    int tempColumn = p->column - newColumn;
    if (fabs (tempColumn) == fabs (tempRow))
    {
        return true;
    }
    
    return false;
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
    return (p->column != newColumn && p->row == newRow) || (p->column == newColumn && p->row != newRow);
}

bool validateKingMove(piece *p, int newRow, int newColumn){
    int column = p->column-newColumn;
    int row = p->row-newRow;
    return column<2&&row<2&&-2<column&&-2<row;
}

bool movePiece(piece *p, int newRow, int newColumn){
    if(p->column == newColumn && p->row == newRow){
        return false;
    }
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
    int temp = board[newRow][newColumn];
    if (temp != 0 && chessPieces[temp]->white == p->white){
        valid = false;
    }
    return valid;
}

void upgradePiece();

void newGame(){
    enum pieceType pt = Queen;
    chessPieces[0] = newPieces(0, 5, 4, pt, true);
}

bool loadGame();

#endif