#ifndef NODE_H
#define NODE_H
struct Node
{
  char symbol;
  int weight;
  Node* parent;
  Node* l_child;
  Node* r_child;
};
#endif