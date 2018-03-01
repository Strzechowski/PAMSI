#include <iostream>
#include "Tree.h"

using namespace std;


void preorder(Node * node)
{
    if (node != NULL)
    {
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node * node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
}

void postorder(Node * node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
}


int main()
{
    Tree tree;
    int data;
    cout << "Podaj dane do drzewa (wpisz 999, aby zakonczyc)" << endl;
    cin >> data;
    while(data != 999)
    {
        tree.add_node(data);
        cin >> data;
    }


    cout << "Pre-order:  ";
    preorder(tree.root);
    cout << " " << endl;

    cout << "In-order:   ";
    inorder(tree.root);
    cout << " " << endl;

    cout << "Post-order: ";
    postorder(tree.root);
    cout << " " << endl;

    cout << tree.get_height(tree.root);

    return 0;
}
