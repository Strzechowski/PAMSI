#include "Board.h"
#include <windows.h>

Board::Board(int boardSide)
{
    SideOfBoard = boardSide;
    BoardSize = boardSide * boardSide - 1;
}

Board::~Board()
{
    //dtor
}

bool Board::checkIfWon(int board[], int whichFigure)
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

bool Board::checkIfDrawn(int board[])
{
    int boardSize = SideOfBoard * SideOfBoard -1;
    for (int i = 1; i <= boardSize; i++)
    {
        if( board[i] == 0)
            return false;
    }
    return true;
}



void Board::play()
{
    bool win;
    //int pickYourSide;
    int boardSize = SideOfBoard * SideOfBoard;
    int board[boardSize] = {0};
    system("CLS");
    //cout << "Krzyzyk zawsze zaczyna!" << endl;
    cout << "Gracz jest krzyzykiem, a komputer kolkiem";
    //cin >> pickYourSide;

    //placeSomethinOnBoard(board, 4, 1);
   // placeSomethinOnBoard(board, 3, 1);
   // placeSomethinOnBoard(board, 1, 1);

    while (!win)
    {
        humanMove(board, 1);
        win = checkIfWon(board, 1);

        if (win == true)
            break;
        printTheBoard(board);


        computerMove(board);
        win = checkIfWon(board, -1);
        if (win == true)
            break;

        printTheBoard(board);
    }
        cout << "NO JEST" << endl;
}

void Board::humanMove(int board[], int yourSide)
{
    int horizontal, vertical;
    //system("CLS");
    printTheBoard(board);

    cout << endl;
    cout << "Wybierz pole ktore chcesz zajac." << endl;
    cout << "Numer w poziomie: ";
    cin >> horizontal;
    cout << "Numer w pionie: ";
    cin >> vertical;

    int actualArrayElement = countActualElement(vertical, horizontal);
    //zapobiegamy wybrania zajetego pola
    if ( board[actualArrayElement] != 0)
    {
        humanMove(board, yourSide);
    }
    else
    {
        placeSomethinOnBoard(board, actualArrayElement, yourSide);
    }
}


int * Board::placeSomethinOnBoard(int board[], int placeInArray, int whatElement)
{
    board[placeInArray] = whatElement;
    return board;
}

int Board::countActualElement(int verticalNumber, int horizontalNumber)
{
    int element = (verticalNumber - 1) * SideOfBoard + horizontalNumber -1;
    return element;
}


void Board::printSeparatingLine()
{
    for (int j = 0; j <= SideOfBoard; j++)
    {
        cout << "---+";
    }
    cout << endl;
}

void Board::printTheBoard(int board[])
{
    //Najpierw wypisujemy numery poziome u szczytu planszy
    cout << "   " << endl;
    cout << "   ";
    for (int i = 1; i <= SideOfBoard; i++)
    {
        cout << "  " << i;
        if (i < 10)
            cout << " ";
    }
    cout << endl;

    //Teraz bedziemy wypisywac kolejne rzedy
    for (int i = 1; i <= SideOfBoard; i++)
    {
        printSeparatingLine();

        cout << " " << i;
            if (i < 10)
                cout << " ";
        for (int j = 1; j <= SideOfBoard; j++)
        {
            int actualElement = countActualElement(i, j);
            if (board[actualElement] == 0)
                cout << "|   ";
            else if (board[actualElement] == -1)
                cout << "| X ";
            else if (board[actualElement] == 1)
                cout << "| O ";
        }
        cout << "|"<< endl;

    }
     printSeparatingLine();
}


int Board::minimax(int board[], int whichPlayer)
{
   // cout << "MINI " << endl;
    int mnx, m;
    //Sprawdzamy czy dany gracz wygral
    if ( checkIfWon(board, whichPlayer) )
        return (whichPlayer * (-1));

    if ( checkIfDrawn(board) )
        return 0;

    //zmiana gracza
    whichPlayer *= (-1);

    mnx = whichPlayer * 10;

    for (int i = 0; i <= BoardSize; i++)
    {
        if( board[i] == 0 )
        {
            board[i] = whichPlayer;
            m = minimax(board, whichPlayer);
            board[i] = 0;
            //TO PEWNIE MOZNA ZROBIC Z ABS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if ( (whichPlayer == 1) && (m < mnx) )
                mnx = m;
            if ( (whichPlayer == (-1) ) && (m > mnx) )
                mnx = m;
        }
    }
    return mnx;
}


void Board::computerMove(int board[])
{
    int mnx, m, whereToMove;

    cout << whereToMove << "  aaaaa" << endl;
    mnx = -10;
    for (int i = 0; i <= BoardSize; i++)
    {
        if( board[i] == 0 )
        {
            //cout << i << endl;
            board[i] = -1;
            m = minimax(board, -1);
            board[i] = 0;
            if (  m > mnx )
            {
                mnx = m;
                whereToMove = i;
                cout << whereToMove << endl;
            }
        }
    }
    cout << whereToMove << " bb"<< endl;
    placeSomethinOnBoard(board, whereToMove, -1);
}
