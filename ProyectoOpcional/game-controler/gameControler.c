#ifndef gameControler
#define gameControler

#include "pieces.c"
#include <stdbool.h>
#include <stdio.h>
#include <math.h> //https://www.aprenderaprogramar.com/index.php?option=com_content&view=article&id=909:funciones-matematicas-en-c-redondeo-valor-absoluto-potencia-trigonometricas-raiz-cuadrada-cu00520f&catid=82&Itemid=210
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib") // Winsock Library

char boardID[15];
int board[9][9] = {0};
piece *chessPieces[33];
bool whiteTurn;
bool status;

#define BUFLEN 512
#define PORT 6666
#define ADDRESS "127.0.0.1" // aka "localhost"

bool checkColumn(int column, int actualRow, int newRow)
{
    bool up = true;
    bool valid = true;
    if (actualRow > newRow)
    {
        up = false;
    }
    while (actualRow != newRow)
    {
        if (up)
        {
            actualRow++;
        }
        else
        {
            actualRow--;
        }

        if (board[actualRow][column] != 0)
        {
            valid = false;
            break;
        }
    }
    return valid;
}

bool checkRow(int row, int actualColumn, int newColumn)
{
    bool left = true;
    bool valid = true;
    if (actualColumn < newColumn)
    {
        left = false;
    }
    while (actualColumn != newColumn)
    {
        if (left)
        {
            actualColumn--;
        }
        else
        {
            actualColumn++;
        }
        if (board[row][actualColumn] != 0)
        {
            valid = false;
            break;
        }
    }
    return valid;
}

bool checkDiagonal(int actualRow, int newRow, int actualColumn, int newColumn)
{
    bool valid = true;
    while (fabs(actualRow - newRow) != 1)
    {
        if (actualRow < newRow)
        {
            actualRow++;
        }
        else
        {
            actualRow--;
        }
        if (actualColumn < newColumn)
        {
            actualColumn++;
        }
        else
        {
            actualColumn--;
        }
        if (board[actualRow][actualColumn] != 0)
        {
            valid = false;
            break;
        }
    }

    return valid;
}

bool validatePawnMove(piece *p, int newRow, int newColumn, bool rivalPiece)
{
    if (p->white)
    {
        if (p->column != newColumn)
        {
            if ((newColumn - 1 == p->column || newColumn + 1 == p->column) && p->row + 1 == newRow && rivalPiece)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (4 == newRow && p->row == 2 && !rivalPiece)
        {
            return true;
        }
        else if (p->row + 1 == newRow && !rivalPiece)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (p->column != newColumn)
        {
            if ((newColumn - 1 == p->column || newColumn + 1 == p->column) && p->row - 1 == newRow && rivalPiece)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (5 == newRow && p->row == 7 && !rivalPiece)
        {
            return true;
        }
        else if (p->row - 1 == newRow && !rivalPiece)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool validateBishopMove(piece *p, int newRow, int newColumn)
{
    bool valid = checkDiagonal(p->row, newRow, p->column, newColumn);
    int tempRow = p->row - newRow;
    int tempColumn = p->column - newColumn;
    if (fabs(tempColumn) == fabs(tempRow) && valid)
    {
        return true;
    }

    return false;
}

bool validateKnightMove(piece *p, int newRow, int newColumn)
{
    if (p->column + 2 == newColumn && (p->row + 1 == newRow || p->row - 1 == newRow))
    {
        return true;
    }
    else if (p->column - 2 == newColumn && (p->row + 1 == newRow || p->row - 1 == newRow))
    {
        return true;
    }
    else if (p->row + 2 == newRow && (p->column + 1 == newColumn || p->column - 1 == newColumn))
    {
        return true;
    }
    else if (p->row - 2 == newRow && (p->column + 1 == newColumn || p->column - 1 == newColumn))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validateRookMove(piece *p, int newRow, int newColumn)
{
    bool valid;
    if (newColumn == p->column)
    {
        valid = checkColumn(newColumn, p->row, newRow);
    }
    else
    {
        valid = checkRow(newRow, p->column, newColumn);
    }
    return ((p->column != newColumn && p->row == newRow) || (p->column == newColumn && p->row != newRow)) && valid;
}

bool validateKingMove(piece *p, int newRow, int newColumn)
{
    int column = p->column - newColumn;
    int row = p->row - newRow;
    return column <= 1 && row <= 1 && -1 <= column && -1 <= row;
}

bool validateMove(int currentRow, int currentColumn, int newRow, int newColumn)
{
    piece *p = chessPieces[board[currentRow][currentColumn]];
    if (p->white != whiteTurn)
    {
        return false;
    }
    else if (p->column == newColumn && p->row == newRow)
    {
        return false;
    }
    int temp = board[newRow][newColumn];
    /*printf("temp = %i \n", temp);*/
    // check if occupied and same color
    if (temp != 0)
    {
        if (chessPieces[temp]->white == p->white)
        {
            return false;
        }
    }
    else if (8 < newRow || 8 < newColumn || newRow < 1 || newColumn < 1)
    {
        /* code */
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
        break;
    }
    return valid;
}

bool kingAtRisk()
{
    int adjustment = 0;
    int pieceId = 1;
    piece *king;
    if (!whiteTurn)
    {
        adjustment = 16;
        king = chessPieces[16 + adjustment];
    }
    bool valid = false;
    piece *p = chessPieces[pieceId];
    while (pieceId <= 15)
    {
        switch (p->pieceType)
        {
        case Bishop:
            valid = validateBishopMove(p, king->row, king->column);
            break;
        case Knight:
            valid = validateKnightMove(p, king->row, king->column);
            break;
        case Rook:
            valid = validateRookMove(p, king->row, king->column);
            break;
        case Queen:
            valid = validateBishopMove(p, king->row, king->column) || validateRookMove(p, king->row, king->column);
            break;
        default:
            if (whiteTurn && (p->column + 1 == king->column || p->column - 1 == king->column) && king->row == p->row + 1)
            {
                valid = true;
            }
            else if (whiteTurn && fabs(p->column - king->column) == 1 && king->row == p->row - 1)
            {
                valid = true;
            }
            break;
        }
        pieceId++;
    }
    return valid;
}

void upgradePiece(piece *p)
{
    enum pieceType pt = Queen;
    promote(p, pt);
}

bool movePiece(int currentRow, int currentColumn, int newRow, int newColumn)
{
    piece *p = chessPieces[board[currentRow][currentColumn]];
    if (board[newRow][newColumn] != 0)
    {
        piece *enemyPiece = chessPieces[board[newRow][newColumn]];
        newPosition(enemyPiece, 0, 0);
    }
    enum pieceType pt = Pawn;
    if (p->pieceType == pt && (newRow == 8 || newRow == 1))
    {
        upgradePiece(p);
    }
    board[p->row][p->column] = 0;
    newPosition(p, newRow, newColumn);
    board[newRow][newColumn] = p->id;
    whiteTurn = !whiteTurn;
    return kingAtRisk();
}

void newGame(/*char boardid[15]*/)
{
    //strcpy(boardID, boardid);
    enum pieceType pt = Pawn;
    whiteTurn = true;
    status = false;
    int id = 1;
    int column = 1;
    int whiteLine = 2;
    int blackLine = 7;
    while (id <= 8)
    {
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id + 16] = newPieces(id + 16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id + 16;
        column++;
        id++;
    }
    whiteLine = 1;
    blackLine = 8;
    column = 1;
    pt = Rook;
    while (id <= 10)
    {
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id + 16] = newPieces(id + 16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id + 16;
        column = 8;
        id++;
    }
    column = 2;
    pt = Knight;
    while (id <= 12)
    {
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id + 16] = newPieces(id + 16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id + 16;
        column = 7;
        id++;
    }
    column = 3;
    pt = Bishop;
    while (id <= 14)
    {
        chessPieces[id] = newPieces(id, whiteLine, column, pt, true);
        chessPieces[id + 16] = newPieces(id + 16, blackLine, column, pt, false);
        board[whiteLine][column] = id;
        board[blackLine][column] = id + 16;
        column = 6;
        id++;
    }
    pt = Queen;
    chessPieces[id] = newPieces(id, 4, whiteLine, pt, true);
    chessPieces[id + 16] = newPieces(id + 16, 4, blackLine, pt, false);
    board[whiteLine][column] = id;
    board[blackLine][column] = id + 16;
    id++;
    pt = King;
    chessPieces[id] = newPieces(id, 5, whiteLine, pt, true);
    chessPieces[id + 16] = newPieces(id + 16, 5, blackLine, pt, false);
    board[whiteLine][column] = id;
    board[blackLine][column] = id + 16;
}

bool loadGame(/*char boardid[15]*/)
{
    //strcpy(boardID, boardid);

}

void clearBoard()
{
    piece *p;
    for (int i = 0; i < 32; i++)
    {
        p = chessPieces[i];
        chessPieces[i] = NULL;
        free(p);
    }
}

// https://stackoverflow.com/questions/1981459/using-threads-in-c-on-windows-simple-example
DWORD WINAPI ThreadFunc(void *data)
{
    return 0;
}

// https://github.com/michaelg29/yt-challenges/blob/master/29%20-%20Winsock/29.1%20-%20Server/main.c
int main()
{
    printf("Hello, world!\n");
    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
    int res, sendRes;

    // INITIALIZATION ===========================
    WSADATA wsaData; // configuration data
    res = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (res)
    {
        printf("Startup failed: %d\n", res);
        return 1;
    }
    // ==========================================

    // SETUP SERVER =============================

    // construct socket
    SOCKET listener;
    listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == INVALID_SOCKET)
    {
        printf("Error with construction: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // bind to address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ADDRESS);
    address.sin_port = htons(PORT);
    res = bind(listener, (struct sockaddr *)&address, sizeof(address));
    if (res == SOCKET_ERROR)
    {
        printf("Bind failed: %d\n", WSAGetLastError());
        closesocket(listener);
        WSACleanup();
        return 1;
    }

    // set as a listener
    res = listen(listener, SOMAXCONN);
    if (res == SOCKET_ERROR)
    {
        printf("Listen failed: %d\n", WSAGetLastError());
        closesocket(listener);
        WSACleanup();
        return 1;
    }
    // ==========================================

    printf("Accepting on %s:%d\n", ADDRESS, PORT);

    // HANDLE A CLIENT ==========================

    // accept client socket
    SOCKET client;
    struct sockaddr_in clientAddr;
    int clientAddrlen;
    client = accept(listener, NULL, NULL);
    if (client == INVALID_SOCKET)
    {
        printf("Could not accept: %d\n", WSAGetLastError());
        closesocket(listener);
        WSACleanup();
        return 1;
    }

    // get client information
    getpeername(client, (struct sockaddr *)&clientAddr, &clientAddrlen);
    printf("Client connected at %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // send welcome message
    char *welcome = "Welcome to the server :)";
    sendRes = send(client, welcome, strlen(welcome), 0);
    if (sendRes != strlen(welcome))
    {
        printf("Error sending: %d\n", WSAGetLastError());
        shutdown(client, SD_BOTH);
        closesocket(client);
    }

    // receive messages
    char recvbuf[BUFLEN];
    do
    {
        res = recv(client, recvbuf, BUFLEN, 0);
        if (res > 0)
        {
            recvbuf[res] = '\0';
            printf("Message received (%d): %s\n", res, recvbuf);

            if (!memcmp(recvbuf, "/quit", 5 * sizeof(char)))
            {
                // received quit command
                printf("Closing connection.\n");
                clearBoard();
                break;
            }
            if(memcmp(recvbuf, "Create Board", sizeof("Create Board"))){
                newGame();
            }else if (memcmp(recvbuf, "Load Board", sizeof("Load Board"))){
                loadGame();
            }else if(memcmp(recvbuf, "Move", sizeof("Move"))){
                //validateMove();
            }
            
            // echo message back
            sendRes = send(client, recvbuf, res, 0);
            if (sendRes != res)
            {
                printf("Error sending: %d\n", WSAGetLastError());
                shutdown(client, SD_BOTH);
                closesocket(client);
                break;
            }
        }
        else if (!res)
        {
            // client disconnected
            printf("Closing connection.\n");
            break;
        }
        else
        {
            printf("Receive failed: %d\n", WSAGetLastError());
            break;
        }
    } while (res > 0);

    // shutdown client
    res = shutdown(client, SD_BOTH);
    if (res == SOCKET_ERROR)
    {
        printf("Client shutdown failed: %d\n", WSAGetLastError());
    }
    closesocket(client);

    // ==========================================

    // CLEANUP ==================================
    // shut down server socket
    closesocket(listener);

    // cleanup WSA
    res = WSACleanup();
    if (res)
    {
        printf("Cleanup failed: %d\n", res);
        return 1;
    }
    // ==========================================

    printf("Shutting down.\nGood night.\n");

    return 0;
}

int main()
{
    crearSocker();
    return 0;
}

#endif