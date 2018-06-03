#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    int boardSide;
    cout << "Witam w grze w kolko i krzyzyk." << endl;
    cout << "Prosze podac wielkosc boku planszy do gry: ";
    cin >> boardSide;


    Board board(boardSide);
    board.play();

    return 0;
}
