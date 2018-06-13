#include "BoardSituation.h"

BoardSituation::BoardSituation(int sideOfBoard, int boardSize)
{
    SideOfBoard = sideOfBoard;
    BoardSize = boardSize;
}

BoardSituation::~BoardSituation()
{
    //dtor
}

int BoardSituation::countActualElement(int verticalNumber, int horizontalNumber)
{
    int element = (verticalNumber - 1) * SideOfBoard + horizontalNumber -1;
    return element;
}

bool BoardSituation::checkIfWon(int board[], int whichFigure)
{
    //Sprawdzamy poziomo
    for(int i = 1; i <= SideOfBoard; i++)
    {
       for(int j = 1; j <= SideOfBoard; j++)
       {
            int actualElement = countActualElement(i, j);
            if( board[actualElement] != whichFigure )
                break;
            if( j == SideOfBoard)
                return true;
       }
    }

    //Nastepnie pionowo
    for(int j = 1; j <= SideOfBoard; j++)
    {
        for(int i = 1; i <= SideOfBoard; i++)
        {

            int actualElement = countActualElement(i, j);
            if( board[actualElement] != whichFigure )
                break;
            if( i == SideOfBoard)
                return true;
        }
    }

    //na skos od lewego górnego do prawego dolnego
    int boardSize = SideOfBoard * SideOfBoard -1;
    for(int i = 0; i <= boardSize; i+=SideOfBoard+1)
    {
        if( board[i] != whichFigure)
            break;
        if( i == boardSize )
                return true;
    }

    //i przeciwnie
    for(int i = SideOfBoard - 1; i < boardSize ; i+=SideOfBoard-1)
    {
        if( board[i] != whichFigure)
            break;
        if( i == (boardSize - SideOfBoard + 1) )
            return true;
    }

    return false;
}

bool BoardSituation::checkIfDrawn(int board[])
{
    for (int i = 1; i <= BoardSize; i++)
    {
        if( board[i] == 0)
            return false;
    }
    return true;
}
