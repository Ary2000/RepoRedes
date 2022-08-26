#ifndef gameControler
#define gameControler

#include "pieces.c"
#include <stdbool.h>
#include <stdio.h>
#include <math.h> //https://www.aprenderaprogramar.com/index.php?option=com_content&view=article&id=909:funciones-matematicas-en-c-redondeo-valor-absoluto-potencia-trigonometricas-raiz-cuadrada-cu00520f&catid=82&Itemid=210
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <windows.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
        if(enemyPiece->pieceType == King){
            status = false;
            return false;
        }
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
    // strcpy(boardID, boardid);
    enum pieceType pt = Pawn;
    whiteTurn = true;
    status = true;
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
    column--;
    board[whiteLine][column] = id;
    board[blackLine][column] = id + 16;
    id++;
    pt = King;
    chessPieces[id] = newPieces(id, 5, whiteLine, pt, true);
    chessPieces[id + 16] = newPieces(id + 16, 5, blackLine, pt, false);
    column--;
    board[whiteLine][column] = id;
    board[blackLine][column] = id + 16;
}

bool loadGame(/*char boardid[15]*/)
{
    // strcpy(boardID, boardid);
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


// https://github.com/michaelg29/yt-challenges/blob/master/29%20-%20Winsock/29.1%20-%20Server/main.c
int main()
{
    printf("Hello, world!\n");
    int res, sendRes;
    // https://www.geeksforgeeks.org/socket-programming-cc/
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";
  
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
        == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
  
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // send welcome message
    char *welcome = "Welcome to the server :)";
    sendRes = send(new_socket, welcome, strlen(welcome), 0);
    if (sendRes != strlen(welcome))
    {
        printf("Error sending a message\n");
        shutdown(server_fd, SHUT_RDWR);
        close(new_socket);
    }

    // receive messages
    char recvbuf[BUFLEN];
    do
    {
        res = recv(new_socket, recvbuf, BUFLEN, 0);
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
            if (!memcmp(recvbuf, "Create Board", sizeof("Create Board")))
            {
                newGame();
            }
            else if (!memcmp(recvbuf, "Load Board", sizeof("Load Board")))
            {
                loadGame();
            }
            else if (!memcmp(recvbuf, "Move", sizeof("Move")))
            {
                res = recv(new_socket, recvbuf, BUFLEN, 0);
                int currentColumn = (int)recvbuf[0];
                currentColumn -= (int)'a';
                currentColumn++;
                int currentRow = (int)recvbuf[1];
                currentRow -= (int)'0';
                sendRes = send(new_socket, recvbuf, res, 0);
                res = recv(new_socket, recvbuf, BUFLEN, 0);
                int newColumn = (int)recvbuf[0];
                newColumn -= (int)'a';
                newColumn++;
                int newRow = (int)recvbuf[1];
                newRow -= (int)'0';
                bool respuesta = validateMove(currentRow, currentColumn, newRow, newColumn);
                if (respuesta == true)
                {
                    movePiece(currentRow, currentColumn, newRow, newColumn);
                    sendRes = send(new_socket, "1", 1, 0);
                }
                else
                    sendRes = send(new_socket, "0", 1, 0);
            }

            // echo message back
            sendRes = send(new_socket, recvbuf, res, 0);
            if (sendRes != res)
            {
                printf("Error sending\n");
                close(new_socket);
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
            printf("Receive failed\n");
            break;
        }
    } while (res > 0);

    // shutdown client
    shutdown(server_fd, SHUT_RDWR);
    close(new_socket);

    // ==========================================

    // CLEANUP ==================================
    // shut down server socket
    close(server_fd);


    // ==========================================

    printf("Shutting down.\nGood night.\n");

    return 0;
}

#endif