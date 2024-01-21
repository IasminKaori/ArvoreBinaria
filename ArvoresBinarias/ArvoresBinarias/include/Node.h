#ifndef NODE_H
#define NODE_H

#include<cstddef>

class Node
{
    public:
        Node *left;
        Node *right;
        Node();
        Node(int key, Node *left, Node* right);
        virtual ~Node();
        void setKey(int key);
        int getKey();
        int valor();
        int data();

    private:
        int key;
};

Node::Node()
{
   left=right=NULL;
}
Node::Node(int key, Node *left=NULL, Node* right=NULL)
{
   this->key=key;
   this->left = left;
   this->right = right;
}

void Node::setKey(int key)
{
    this->key = key;
}

int Node::getKey()
{
    return this->key;
}

Node::~Node()
{
    //dtor
}


#endif // NODE_H
