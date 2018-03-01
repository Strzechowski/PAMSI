#ifndef TREE_H
#define TREE_H
#include <iostream>


using namespace std;

/*
Struktura wezla
*/
struct Node
{
    int value;
    int balance;
    Node * left;
    Node * right;
    Node * up;
};

/*
Klasa drzewa
*/
class Tree
{
public:
    Node * root;


    /*
    Inicjujemy korzen
    */
    Tree();
    virtual ~Tree();

    /*
    Funkcja zwraca wyokosc drzewa zaczynajac od wezla, ktory jej podamy.
    */
    int get_height(Node * node);


    /*
    Funkcja umo¿liwia dodanie nowego wezla, sprawdza czy mamy korzen i tworzy go lub uruchamia
    inna funkcje, w ktorej wykorzystamy rekurencje.
    */
    void add_node(int nodeValue);
    /*
    Nie gotowe
    */
    void remove_node(int nodeValue, Node * nodeThatMightBeRemoved);

private:

    /*
    Funkcja wykorzystuje rekurencje, aby dodac nowy wezel do juz istniejacych.
    */
    void add_node(int nodeValue, Node * nodeToInsert);
};

#endif // TREE_H
