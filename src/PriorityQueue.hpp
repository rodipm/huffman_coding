#ifndef PRIORITY_H
#define PRIORITY_H

#include "Node.cpp"


class PriorityQueue
{
  struct QueueElement
  {
    Node* node;
    QueueElement* next;
  };
  QueueElement* queue;
  int size;

public:
  PriorityQueue();
  ~PriorityQueue();

  int getSize()
  {
    return this->size;
  }

  void push(Node* node);
  Node* pop();

  void print();
    
};
#endif
