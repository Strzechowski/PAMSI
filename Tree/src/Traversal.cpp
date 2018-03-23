#include "Traversal.h"

Traversal::Traversal()
{
    //ctor
}

Traversal::~Traversal()
{
    //dtor
}

/*********
Przejscia
**********/
void Traversal::preorder(const Node * node)
{
    if (node != NULL)
    {
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void Traversal::inorder(const Node * node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
}

void Traversal::postorder(const Node * node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
}
