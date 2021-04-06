#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue()
{
  this->size = 0;
  this->queue = nullptr;
}

PriorityQueue::~PriorityQueue()
{
  QueueElement* curElement = this->queue;

  while(curElement != nullptr)
  {

    QueueElement* nextElement = curElement->next;
    delete curElement; 
    curElement = nextElement;
  }  
}

void PriorityQueue::push(Node* node)
{
  if (this->size == 0)
  {
    QueueElement* qElement = new QueueElement();
    qElement->prev = nullptr;
    qElement->next = nullptr;
    qElement->node = node;
    this->queue = qElement;
    this->size--;
  }
  
}

Node* PriorityQueue::pop()
{
  Node* node = nullptr; 
  if (this->size > 0)
  {
    QueueElement* nextElement = this->queue->next;
    nextElement->prev = nullptr;

    node = this->queue->node;

    QueueElement* oldElement = this->queue;

    this->queue = nextElement;

    delete oldElement;
  }
  return node;
}
