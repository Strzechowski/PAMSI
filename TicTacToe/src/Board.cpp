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


void Board::play()
{
    Computer computer(SideOfBoard, BoardSize);
    int whereToMove;
    bool win = false;
    //tablica do planszy
    int boardSize = SideOfBoard * SideOfBoard;
    int board[boardSize] = {0};

    while (!win)
    {
        humanMove(board, 1);
        if( checkScore(board, 1) )
            break;


        whereToMove = computer.computerMove(board);
        placeSomethinOnBoard(board, whereToMove, -1);
        printTheBoard(board);
        if( checkScore(board, -1) )
            break;
    }
    printTheBoard(board);
}

int Board::checkScore(int board[], int whichSide)
{
    int win, draw;
    //Pomocnicza klasa pozwala nam na sprawdzenie czy gra sie skoczyla
    BoardSituation boardSituation(SideOfBoard, BoardSize);

    cout << endl;
    win = boardSituation.checkIfWon(board, whichSide);
    if (win)
    {
        system("CLS");
        cout << "Wygrywa ";
        if (whichSide == 1)
            cout << "Gracz!" << endl;
        else
            cout << "Komputer!" << endl;
        return 1;
    }

    draw = boardSituation.checkIfDrawn(board);
    if (draw)
    {
        system("CLS");
        cout << "Mamy remis!" << endl;
        return 1;
    }
    return 0;
}

void Board::humanMove(int board[], int yourSide)
{
    int horizontal, vertical;
    //czyszczenie ekranu
    system("CLS");
    printTheBoard(board);

    cout << endl;
    cout << "Wybierz pole ktore chcesz zajac." << endl;
    cout << "Numer w poziomie: ";
    cin >> horizontal;
    cout << "Numer w pionie: ";
    cin >> vertical;

    int actualArrayElement = countActualElement(vertical, horizontal);

    if ( board[actualArrayElement] != 0)
    {
        humanMove(board, yourSide);
    }
    else
    {
        //w razie wybrania zajetego pola wywolamy funkcje ponownie
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
