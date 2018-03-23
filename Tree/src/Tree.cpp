#include "Tree.h"

/********************************************
Komentarze do funkcji znajduja sie w pliku .h
*********************************************/

Tree::Tree()
{
    root = NULL;
    nodeToBeBalanced = NULL;
}

Tree::~Tree()
{
    //dtor
}



/***************
Wsokosc drzewa
****************/
int Tree::get_root_height()
{
    return get_height(root);
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


/****************
Dodawanie wezlow
*****************/
Node * Tree::initialize_node(int nodeValue, Node * fatherNode = NULL)
{
    Node * node = new Node;
    node->up = fatherNode;
    node->left = NULL;
    node->right = NULL;
    node->value = nodeValue;
    node->balance = 0;

    return node;
}


void Tree::add_node(int nodeValue)
{
    if (root == NULL)
    {
        root = initialize_node(nodeValue);
    }
    else
    {
        add_node(nodeValue, root);
    }
}


void Tree::add_node(int nodeValue, Node * nodeToInsert)
{

    if (nodeToInsert->value > nodeValue)
    {
        if (nodeToInsert->left == NULL)
        {
            nodeToInsert->left = initialize_node(nodeValue, nodeToInsert);

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
            nodeToInsert->right = initialize_node(nodeValue, nodeToInsert);

            //Sprawdzamy balans wezlow ponad nowo dodanym
            check_balance(nodeToInsert);
        }
        else
        {
            add_node(nodeValue, nodeToInsert->right);
        }
    }
}



/****************
Rotacje i balans
*****************/

/*
Rotacje sa troche zagmatwane ale rysunek w .h wiele wyjasnia
*/
Node * Tree::rotation_right(Node * node)
{
    Node * A = node->up;
    Node * B = node;
    Node * C = node->left;

    if (A != NULL)
    {
        if(A->value < B->value)
        {
            A->right = C;
        }
        else
        {
            A->left = C;
        }
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
        if (A->value < B->value)
        {
            A->right = C;
        }
        else
        {
            A->left = C;
        }
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
    if (nodeToCheck != NULL)
    {
        //najpierw liczymy balans
        nodeToCheck->balance = get_height(nodeToCheck->right) - get_height(nodeToCheck->left);

        //potem sprawdzamy jaka rotacje wykonac
        if (nodeToCheck->balance == 2)
        {
            if (nodeToCheck->right->balance >= 0)
            {
                nodeToCheck = rotation_left(nodeToCheck);
            }
            else
            {
                nodeToCheck = rotation_right(nodeToCheck->right);
                nodeToCheck = rotation_left(nodeToCheck->up);
            }
        }
        if (nodeToCheck->balance == -2)
        {
            if (nodeToCheck->left->balance >= 0)
            {
                nodeToCheck = rotation_left(nodeToCheck->left);
                nodeToCheck = rotation_right(nodeToCheck->up);
            }
            else
            {
                nodeToCheck = rotation_right(nodeToCheck);
            }
        }
        else
        {
            //uruchamiamy dalsze rekurencyjne liczenie balansu
            check_balance(nodeToCheck->up);
        }
    }
}



/*********************
    USUWANIE WEZLOW
**********************/
void Tree::remove_node(int nodeValue)
{
    remove_node(nodeValue, root);
    check_balance(nodeToBeBalanced);
}


Node * Tree::remove_node(int nodeValue, Node * nodeToBeRemoved)
{
    if (nodeToBeRemoved != NULL)
    {

        if (nodeToBeRemoved->value > nodeValue)
        {
            nodeToBeRemoved->left = remove_node(nodeValue, nodeToBeRemoved->left);
        }

        else if (nodeToBeRemoved->value < nodeValue)
        {
            nodeToBeRemoved->right = remove_node(nodeValue, nodeToBeRemoved->right);
        }
        else   //rzeczywiste usuwanie
        {
            //jeden potomek lub ich brak
            if ( (nodeToBeRemoved->right == NULL ) )
            {
                Node * temp = nodeToBeRemoved->left;
                nodeToBeBalanced = nodeToBeRemoved->up; //zapisanie wezla, od ktorego bedziemy sprawdzac balans
                delete nodeToBeRemoved;
                return temp;
            }
            else if ( (nodeToBeRemoved->left == NULL ) )
            {
                Node * temp = nodeToBeRemoved->right;
                nodeToBeBalanced = nodeToBeRemoved->up;
                delete nodeToBeRemoved;
                return temp;
            }
            else
            {
                //jesli wezel ma 2 potomkow to musimy znalezc najmniejszego potomka
                //w jego prawym drzewie i uzyc jego wartosci jako nowej wartosci wezla
                int newNodeValue = find_the_smallest_node(nodeToBeRemoved->right);
                remove_node(newNodeValue, root);
                nodeToBeRemoved->value = newNodeValue;
            }
        }
    }
    return nodeToBeRemoved;
}

int Tree::find_the_smallest_node(Node * node)
{
    if (node->left != NULL)
    {
        return find_the_smallest_node(node->left);
    }
    else
    {
        int theSmallestValue = node->value;
        return theSmallestValue;
    }
}

