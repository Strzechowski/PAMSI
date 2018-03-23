#ifndef MENU_H
#define MENU_H
#include "Tree.h"

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        /**
        Funkcja sluzy do wyswietlania menu i jego obslugi
        */
        void start();
};


#endif // MENU_H
