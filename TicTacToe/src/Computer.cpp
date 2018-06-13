#include "Computer.h"

Computer::Computer(int sideOfBoard, int boardSize)
{
    BoardSize = boardSize;
    SideOfBoard = sideOfBoard;
}

Computer::~Computer()
{
    //dtor
}


int Computer::computerMove(int board[])
{
    int mnx, m, whereToMove;

    mnx = -10000;
    for (int i = 0; i <= BoardSize; i++)
    {
        if( board[i] == 0 )
        {
            board[i] = -1;
            m = minimax(board, 0, -1, -100000, 100000);
            board[i] = 0;
            if (  m > mnx )
            {
                mnx = m;
                whereToMove = i;
            }
        }
    }
    return whereToMove;
}

int Computer::minimax(int board[], int depth, int whichPlayer, int alpha, int beta)
{
    int mnx, m;
    BoardSituation boardSituation(SideOfBoard, BoardSize);
    //Sprawdzamy czy dany gracz wygral
    if ( boardSituation.checkIfWon(board, whichPlayer) )
        return (whichPlayer * (-100));

    //Sprawdzamy czy jest remis
    if ( boardSituation.checkIfDrawn(board) )
        return 0;

    //Sprawdzamy czy nie przekroczylismy glebokosci
    if ( depth == 5)
        return whichPlayer;

    //zmiana gracza
    whichPlayer *= (-1);

    mnx = whichPlayer * 10000;

    for (int i = 0; i <= BoardSize; i++)
    {
        //sprawdzamy czy pole jest puste
        if( board[i] == 0 )
        {
            //szukamy korzystniejszego ruchu
            board[i] = whichPlayer;
            m = minimax(board, depth+1, whichPlayer, alpha, beta);
            board[i] = 0;

            if ( (whichPlayer == 1) && (m < mnx) )
            {
                mnx = m;
                beta = min(beta, mnx);
            }
            else if ( (whichPlayer == (-1)) && (m > mnx) )
            {
                mnx = m;
                alpha = max(alpha, mnx);
            }

            if (beta <= alpha)
                return mnx;
        }
    }
    return mnx;
}
