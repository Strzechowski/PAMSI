#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Node.h"


using namespace std;

/**
Klasa drzewa
*/
class Tree
{
public:
    Node * root;
    Node * nodeToBeBalanced;

    /**
    *Inicjujemy korzen
    */
    Tree();
    virtual ~Tree();

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
    *Nie gotowe
    */
    Node * remove_node(int nodeValue, Node * nodeThatMightBeRemoved);


    /**
    *Funkcja oblicza balans wezla i wykonuje ewentualne obroty
    */
    void check_balance(Node * nodeToCheck);


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
    *Znajduje najmniejszego potomka wezla
    */
    int find_the_smallest_node(Node * node);

    Node * which_child_to_choose(int nodeValue, Node * nodeFather);

private:

    /**
    *Funkcja wykorzystuje rekurencje, aby dodac nowy wezel do juz istniejacych.
    */
    void add_node(int nodeValue, Node * nodeToInsert);

    /**
    *Funkcja zwraca wysokosc drzewa zaczynajac od wezla, ktory jej podamy.
    */
    int get_height(Node * node);

    /**
    *Inicjalizuje nowy wezel
    */
    Node * initialize_node(int nodeValue, Node * fatherNode);
};

#endif // TREE_H
