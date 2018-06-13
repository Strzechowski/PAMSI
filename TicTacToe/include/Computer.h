#ifndef COMPUTER_H
#define COMPUTER_H
#include "BoardSituation.h"
#include <iostream>
#include <algorithm>

using namespace std;


class Computer
{
    public:
        Computer(int sideOfBoard, int boardSize);
        virtual ~Computer();

        /**
        Funkcja decyduje o ruchu komputera
        */
        int computerMove(int board[]);

    private:
        /**
        Zmienne okreslajace wielkosc planszy
        */
        int BoardSize, SideOfBoard;
        /**
        Funkcja wykorzystuje algorytm minimax.
        Oblicza jakie pole powinien zajac komputer.
        */
        int minimax(int board[], int depth, int whichPlayer, int alpha, int beta);
};

#endif // COMPUTER_H
