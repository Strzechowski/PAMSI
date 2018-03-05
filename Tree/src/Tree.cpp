#include "Tree.h"

/********************************************
Komentarze do funckji znajduja sie w pliku .h
*********************************************/

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    //dtor
}


int Tree::get_height(Node * node)
{
    if(node != NULL)
    {
        int height;
        height = 1 + max( get_height(node->right), get_height(node->left) );
        return height;
    }
    return -1;
}


void Tree::add_node(int nodeValue)
{
    if (root == NULL)
    {
        root = new Node;
        root->up = NULL;
        root->left = NULL;
        root->right = NULL;
        root->value = nodeValue;
        root->balance = 0;
    }
    else
    {
        add_node(nodeValue, root);
    }
}


Node * Tree::rotation_right(Node * node)
{
    Node * A = node->up;
    Node * B = node;
    Node * C = node->left;

    if (A != NULL)
    {
        A->left = C;
        C->up = A;
    }
    else
    {
        root = C;
        C->up = NULL;
    }

    B->left = C->right;

    if (C->right != NULL)
    {
        C->right->up = B->left;
    }

    C->right = B;
    B->up = C;

    return C;
}



Node * Tree::rotation_left(Node * node)
{
    Node * A = node->up;
    Node * B = node;
    Node * C = node->right;

    if (A != NULL)
    {
        A->right = C;
        C->up = A;
    }
    else
    {
        root = C;
        C->up = NULL;
    }

    B->right = C->left;

    if (C->left != NULL)
    {
        C->left->up = B->right;
    }

    C->left = B;
    B->up = C;

    return C;
}


void Tree::check_balance(Node * nodeToCheck)
{
    nodeToCheck->balance = get_height(nodeToCheck->right) - get_height(nodeToCheck->left);
    cout << nodeToCheck->balance << endl;
    cout << "wartosc " << nodeToCheck->value << endl;

    if (nodeToCheck->balance == 2)
    {
        if (nodeToCheck->right->balance == 1)
        {
            nodeToCheck = rotation_left(nodeToCheck);
            cout << "bylem " << endl;
        }
        else
        {
            nodeToCheck = rotation_right(nodeToCheck->right);
            nodeToCheck = rotation_left(nodeToCheck);
        }
    }
    if (nodeToCheck->balance == -2)
    {
        if (nodeToCheck->left->balance == 1)
        {
            nodeToCheck = rotation_left(nodeToCheck->left);
            nodeToCheck = rotation_right(nodeToCheck);
        }
        else
        {
            nodeToCheck = rotation_right(nodeToCheck);
        }
    }


    //Uruchamiamy dalsze rekurencyjne liczenie balansu
    if (nodeToCheck->up != NULL)
    {
        cout << " BYLEM " << endl;
        check_balance(nodeToCheck->up);
    }

}

void Tree::add_node(int nodeValue, Node * nodeToInsert)
{
    if (nodeToInsert->value > nodeValue)
    {
        if (nodeToInsert->left == NULL)
        {
            nodeToInsert->left = new Node;
            nodeToInsert->left->up = nodeToInsert;
            nodeToInsert->left->left = NULL;
            nodeToInsert->left->right = NULL;
            nodeToInsert->left->value = nodeValue;
            nodeToInsert->left->balance = 0;

            //Sprawdzamy balans wezlow ponad nowo dodanym
            check_balance(nodeToInsert);
        }
        else
        {
            add_node(nodeValue, nodeToInsert->left);
        }
    }
    //Nie chcemy, aby dodawane byly wezly o powtarzajacych sie wartosciach.
    else if (nodeToInsert->value < nodeValue)
    {
        if (nodeToInsert->right == NULL)
        {
            nodeToInsert->right = new Node;
            nodeToInsert->right->up = nodeToInsert;
            nodeToInsert->right->left = NULL;
            nodeToInsert->right->right = NULL;
            nodeToInsert->right->value = nodeValue;
            nodeToInsert->right->balance = 0;

            //Sprawdzamy balans wezlow ponad nowo dodanym
            check_balance(nodeToInsert);
        }
        else
        {
            add_node(nodeValue, nodeToInsert->right);
        }
    }
}


void Tree::remove_node(int nodeValue, Node * nodeThatMightBeRemoved)
{
    if(nodeThatMightBeRemoved != NULL)
    {
        if(nodeThatMightBeRemoved->value == nodeValue)
        {

        }
        else if(nodeThatMightBeRemoved->value > nodeValue)
        {
            remove_node(nodeValue, nodeThatMightBeRemoved->left);
        }
        else
        {
            remove_node(nodeValue, nodeThatMightBeRemoved->right);
        }
    }

}
