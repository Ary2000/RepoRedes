#ifndef gameControler
#define gameControler

#include "pieces.c"
#include <stdbool.h>
#include <stdio.h>
#include <math.h> //https://www.aprenderaprogramar.com/index.php?option=com_content&view=article&id=909:funciones-matematicas-en-c-redondeo-valor-absoluto-potencia-trigonometricas-raiz-cuadrada-cu00520f&catid=82&Itemid=210

int boardID;
int board[9][9] = {0};
piece* chessPieces[33];
bool whiteTurn;

bool checkColumn(int column, int actualRow, int newRow){
    bool up = true;
    bool valid = true;
    if(actualRow > newRow){
        up = false;
    }
    while (actualRow != newRow)
    {
        if (up){
            actualRow++;
        }else{
            actualRow--;
        }
        
        if(board[actualRow][column] != 0){
            valid = false;
            break;
        }
    }    
    return valid;
}

bool checkRow(int row, int actualColumn, int newColumn){
    bool left = true;
    bool valid = true;
    if(actualColumn < newColumn){
        left = false;
    }
    while (actualColumn != newColumn)
    {
        if (left){
            actualColumn--;
        }else{
            actualColumn++;
        }
        if(board[row][actualColumn] != 0){
            valid = false;
            break;
        }
    }    
    return valid;
}

bool checkDiagonal(int actualRow, int newRow, int actualColumn, int newColumn){
    bool valid = true;
    while (fabs (actualRow - newRow) != 1)
    {
        if (actualRow < newRow){
            actualRow++;
        }else{
            actualRow--;
        }
        if(actualColumn < newColumn){
            actualColumn++;
        }else{
            actualColumn--;
        }
        if(board[actualRow][actualColumn] != 0){
            valid = false;
            break;
        }
    }
    
    return valid;
}

bool validatePawnMove(piece *p, int newRow, int newColumn, bool rivalPiece){
    if (p->white)
    {
        if (p->column != newColumn)
        {
            if ((newColumn-1 == p->column || newColumn+1 == p->column) && p->row +1 == newRow && rivalPiece)
            {
                return true;
            }else{
                return false;
            }
            
        }else if (4 == newRow && p->row == 2 && !rivalPiece)
        {
            return true;
        }else if (p->row + 1 == newRow  && !rivalPiece)
        {
            return true;
        }else{
            return false;
        } 
    }else{
        if (p->column != newColumn)
        {
            if ((newColumn-1 == p->column || newColumn+1 == p->column) && p->row -1 == newRow && rivalPiece)
            {
                return true;
            }else{
                return false;
            }
            
        }else if (5 == newRow && p->row == 7  && !rivalPiece)
        {
            return true;
        }else if (p->row - 1 == newRow  && !rivalPiece)
        {
            return true;
        }else{
            return false;
        }
    }
}

bool validateBishopMove(piece *p, int newRow, int newColumn){
    bool valid = checkDiagonal(p->row, newRow, p->column, newColumn);
    int tempRow = p->row - newRow;
    int tempColumn = p->column - newColumn;
    if (fabs (tempColumn) == fabs (tempRow) && valid){
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
    bool valid;
    if(newColumn == p->column){
        valid = checkColumn(newColumn, p->row, newRow);
    }else{
        valid = checkRow(newRow, p->column, newColumn);
    }
    return ((p->column != newColumn && p->row == newRow) || (p->column == newColumn && p->row != newRow)) && valid;
}

bool validateKingMove(piece *p, int newRow, int newColumn){
    int column = p->column-newColumn;
    int row = p->row-newRow;
    return column <= 1 && row <= 1 && -1 <= column && -1 <= row;
}

bool movePiece(piece *p, int newRow, int newColumn){
    if(p->column == newColumn && p->row == newRow){
        return false;
    }
    int temp = board[newRow][newColumn];
    /*printf("temp = %i \n", temp);*/
    if (temp != 0){
        if(chessPieces[temp]->white == p->white){
            return false;
        }
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
        valid = validatePawnMove(p, newRow, newColumn, temp != 0);
        if(valid && newRow == 8){
            upgradePiece(p);
        }
        break;
    }
    if(valid){
        board[p->row][p->column] = 0;
        newPosition(p, newRow, newColumn);
        board[newRow][newColumn] = p->id;
        whiteTurn = !whiteTurn;
    }
    return valid;
}

bool kingAtRisk();

void upgradePiece(piece *p){
    enum pieceType pt = Queen;
    promote(p, pt);
}

void newGame(){
    boardID = rand() % 1000;
    enum pieceType pt = Pawn;
    whiteTurn = true;
    int id = 1;
    int column = 1;
    int whiteLine = 2;
    int blackLine = 7;
    while (id <= 8){
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id+16] = newPieces(id+16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id+16;
        column++;
        id++;
    }
    whiteLine = 1;
    blackLine = 8;
    column = 1;
    pt = Rook;
    while (id <= 10){
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id+16] = newPieces(id+16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id+16;
        column = 8;
        id++;
    }
    column = 2;
    pt = Knight;
    while (id <= 12){
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id+16] = newPieces(id+16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id+16;
        column = 7;
        id++;
    }
    column = 3;
    pt = Bishop;
    while (id <= 14){
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id+16] = newPieces(id+16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id+16;
        column = 6;
        id++;
    }
    pt = Queen;
    chessPieces[id] = newPieces(id, 4, whiteLine, pt, true);
    chessPieces[id+16] = newPieces(id+16, 4, blackLine, pt, false);
    board[whiteLine][column] = id;
    board[blackLine][column] = id+16;
    id++;
    pt = King;
    chessPieces[id] = newPieces(id, 5, whiteLine, pt, true);
    chessPieces[id+16] = newPieces(id+16, 5, blackLine, pt, false);
    board[whiteLine][column] = id;
    board[blackLine][column] = id+16;
}

bool loadGame();

void clearBoard(){
    piece* p;
    for (int i = 0; i < 32; i++)
    {
        p = chessPieces[i];
        chessPieces[i] = NULL;
        free(p);
    }
    
}

#endif