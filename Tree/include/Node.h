#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;


/**
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


#endif // NODE_H
