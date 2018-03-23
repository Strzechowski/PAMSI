#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include "Node.h"

/**
Klasa implementujaca przejscia (pre- in- post- order)
*/
class Traversal
{
    public:
        Traversal();
        virtual ~Traversal();

        void preorder(const Node * node);
        void inorder(const Node * node);
        void postorder(const Node * node);

};

#endif // TRAVERSAL_H
