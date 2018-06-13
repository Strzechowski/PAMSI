#ifndef BOARDSITUATION_H
#define BOARDSITUATION_H


class BoardSituation
{
    public:
        BoardSituation(int sideOfBoard, int boardSize);
        virtual ~BoardSituation();

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

    private:
        /**
        Zmienne okreslajace wielkosc planszy
        */
        int SideOfBoard, BoardSize;
};

#endif // BOARDSITUATION_H
