#ifndef BOARD_H
#define BOARD_H
#include "Computer.h"
#include "BoardSituation.h"

using namespace std;


class Board
{
    public:
        Board(int boardSize);
        virtual ~Board();
        /**
        Publiczna funkcja do rozpoczecia gry
        */
        void play();

    private:
        /**
        Zmienne okreslajace wielkosc planszy
        */
        int SideOfBoard, BoardSize;

        /**
        Rysuje plansze w aktualnej sytuacji
        */
        void printTheBoard(int board[]);
        /**
        Prywatna funkcja do rysowania linii oddzielajacych rzedy planszy
        */
        void printSeparatingLine();
        /**
        Umozliwia umieszczenie elementu na planszy(w tablicy)
        */
        int * placeSomethinOnBoard(int board[], int placeInArray, int whatElement);
        /**
        Pozwala czlowiekowi zadecydowac o zajeciu wybranego pola
        */
        void humanMove(int board[], int yourSide);
        /**
        Przelicza pozycje elementu na planszy na element tablicy
        */
        int countActualElement(int verticalNumber, int horizontalNumber);
        /**
        Sprawdza czy gra sie skonczyla
        */
        int checkScore(int board[], int whichSide);
};

#endif // BOARD_H
