#ifndef TREE_H
#define TREE_H
#include "Node.h"


/**
Klasa drzewa
*/
class Tree
{
public:
    /**
    *Inicjujemy korzen
    */
    Tree();
    virtual ~Tree();

    /**
    Zwraca korzen drzewa
    */
    Node * get_root()
    {
        return root;
    }

    /**
    *Uzywa prywatnej funkcji get_height z poziomu korzenia
    */
    int get_root_height();


    /**
    *Funkcja publiczna do uzycia w menu. Umozliwia dodanie nowego wezla,
    *sprawdza czy mamy korzen i tworzy go lub uruchamia
    *funkcje prywatna, w ktorej wykorzystamy rekurencje.
    */
    void add_node(int nodeValue);

    /**
    Funkcja wywoluje funkcje prywatna do usuwania wezla oraz
    sprawdza balans drzewa
    */
    void remove_node(int nodeValue);


private:
    Node * root;
    Node * nodeToBeBalanced;

    /**
    *Funkcja zwraca wysokosc drzewa zaczynajac od wezla, ktory jej podamy.
    *Uznaje, ze sam korzen zwraca wysokosc 0.
    */
    int get_height(Node * node);


    /**
    *Funkcja wykorzystuje rekurencje, aby dodac nowy wezel do juz istniejacych.
    */
    void add_node(int nodeValue, Node * nodeToInsert);


    /**
    *Inicjalizuje nowy wezel
    */
    Node * initialize_node(int nodeValue, Node * fatherNode);


    /**
    *Wykonujemy obrot w lewo wzgledem wezla B.
           A                      A
          / \                    / \
        cos* B     ->          cos* C
            / \                    / \
          B.l  C                  B  C.r
              / \                / \
            C.l  C.r           B.l C.l

    *cos nie ma znaczenia w tym obrocie
    */
    Node * rotation_left(Node * node);


    /**
    *Wykonujemy obrot w prawo wzgledem wezla B.
           A                      A
          / \                    / \
         B   cos*     ->        C  cos
        / \                    / \
       C   B.r               C.l  B
      / \                        / \
    C.l  C.r                   C.r  B.r

    *cos nie ma znaczenia w tym obrocie
    */
    Node * rotation_right(Node * node);


    /**
    *Funkcja oblicza balans wezla i wykonuje ewentualne obroty
    */
    void check_balance(Node * nodeToCheck);


    /**
    *Prywatna funkcja wykorzystujaca rekurencje do usuwania wezla
    */
    Node * remove_node(int nodeValue, Node * nodeThatMightBeRemoved);


    /**
    *Znajduje najmniejszego potomka wezla
    */
    int find_the_smallest_node(Node * node);
};

#endif // TREE_H
