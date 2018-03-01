#include "Tree.h"

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
