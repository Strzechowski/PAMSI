#ifndef BOARD_H
#define BOARD_H
#include <iostream>

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
        Pola przechowuja bok tablicy i ilosc jej pul
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
        Funkcja sprawdza, czy dany gracz wygral
        */
        bool checkIfWon(int board[], int whichFigure);
        /**
        Funkcja sprawdza, czy nastapil remis
        */
        bool checkIfDrawn(int board[]);
        /**
        Przelicza pozycje elementu na planszy na element tablicy
        */
        int countActualElement(int verticalNumber, int horizontalNumber);

        int minimax(int board[], int whichPlayer);
        /**
        Funkcja decyduje o ruchu komputera
        */
        void computerMove(int board[]);
};

#endif // BOARD_H
