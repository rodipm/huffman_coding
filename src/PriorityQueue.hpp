#ifndef PRIORITY_H
#define PRIORITY_H

#include "Node.cpp"

struct QueueElement
{
  Node* node;
  QueueElement* next;
  QueueElement* prev;
};

class PriorityQueue
{
  QueueElement* queue;
  int size;

public:
  PriorityQueue();
  ~PriorityQueue();

  void push(Node* node);
  Node* pop();
    
};
#endif
