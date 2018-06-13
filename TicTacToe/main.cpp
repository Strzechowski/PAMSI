#include "Board.h"

int main()
{
    int boardSide;
    cout << "Witam w grze w kolko i krzyzyk." << endl;
    cout << "Gracz gra kolkiem, a komputer krzyzykiem." << endl;
    cout << "Prosze podac wielkosc boku planszy do gry: ";
    cin >> boardSide;


    Board board(boardSide);
    board.play();

    return 0;
}
