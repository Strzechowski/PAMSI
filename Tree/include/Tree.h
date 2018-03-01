#ifndef TREE_H
#define TREE_H
#include <iostream>


using namespace std;

struct Node
{
    int value;
    int balance;
    Node * left;
    Node * right;
    Node * up;
};

class Tree
{
public:
    Node * root;

    Tree();
    virtual ~Tree();

    void add_node(int nodeValue);
    void remove_node(int nodeValue, Node * nodeThatMightBeRemoved);

private:
    void add_node(int nodeValue, Node * nodeToInsert);
};

#endif // TREE_H
