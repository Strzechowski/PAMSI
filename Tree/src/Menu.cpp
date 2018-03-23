#include "Menu.h"
#include "Traversal.h"
#include <stdlib.h>

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::start()
{
    Tree tree;
    Traversal traversal;
    int menuNumber;
    int data;
    char usedToGoBackToMenu;

    while (menuNumber != 8)
    {
        cout << "Menu:" << endl;
        cout << "1. Dodaj wezly do drzewa" << endl;
        cout << "2. Usun wezel z drzewa" << endl;
        cout << "3. Wypisz wysokosc drzewa" << endl;
        cout << "4. Wyswietl wartosc korzenia drzewa" << endl;
        cout << "5. Przejscie pre-order" << endl;
        cout << "6. Przejscie in-order" << endl;
        cout << "7. Przejscie post-order" << endl;
        cout << "-----------------------------------" << endl;
        cout << "8. Zamknij program" << endl;
        cin >> menuNumber;
        system("cls");
        switch (menuNumber)
        {
        case 1:

            cout << "Podaj liczby do drzewa (wpisz 999, aby zakonczyc)" << endl;
            cin >> data;
            while(data != 999)
            {
                tree.add_node(data);
                cin >> data;
            }
            break;

        case 2:
            cout << "Podaj wartosc wezla do usuniecia" << endl;
            cin >> data;
            tree.remove_node(data);
            break;

        case 3:
            cout << tree.get_root_height() << endl;
            break;

        case 4:
            cout << tree.get_root()->value << endl;
            break;

        case 5:
            traversal.preorder(tree.get_root());
            break;

        case 6:
            traversal.inorder(tree.get_root());
            break;

        case 7:
            traversal.postorder(tree.get_root());
            break;
        }
        cout << " " << endl;
        cout << "Wpisz cokolwiek, aby wyjsc" << endl;
        cin >> usedToGoBackToMenu;
        system("cls");
    }
}
