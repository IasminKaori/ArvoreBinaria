#include "Node.h"

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
