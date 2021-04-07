#include "PriorityQueue.hpp"
#include <iostream>

PriorityQueue::PriorityQueue()
{
  this->size = 0;
  this->queue = nullptr;
}

PriorityQueue::~PriorityQueue()
{
  QueueElement *curElement = this->queue;

  while (curElement != nullptr)
  {
    QueueElement *nextElement = curElement->next;
    delete curElement;
    curElement = nextElement;
  }
}

void PriorityQueue::push(Node *node)
{
  if (this->size == 0)
  {
    QueueElement *qElement = new QueueElement();
    qElement->next = nullptr;
    qElement->node = node;
    this->queue = qElement;
  }
  else
  {
    QueueElement *curElement = this->queue;
    QueueElement *newElement = new QueueElement();
    newElement->node = node;

    if (curElement->node->weight > node->weight)
    {
      newElement->next = curElement;
      this->queue = newElement;
    }
    else
    {
      while (curElement->next != nullptr)
      {

        if (curElement->next->node->weight > node->weight)
          break;

        curElement = curElement->next;
      }

      newElement->next = curElement->next;

      curElement->next = newElement;
    }
  }

  this->size++;
}

Node *PriorityQueue::pop()
{
  Node *node = nullptr;
  if (this->size > 0)
  {
    QueueElement *nextElement = this->queue->next;

    node = this->queue->node;

    QueueElement *oldElement = this->queue;

    this->queue = nextElement;

    delete oldElement;
    this->size--;
  }
  return node;
}

void PriorityQueue::print()
{
  std::cout << "=====" << std::endl;
  QueueElement *curElement = this->queue;

  while (curElement != nullptr)
  {
    if (curElement->node->l_child == nullptr && curElement->node->r_child == nullptr)
      std::cout << curElement->node->symbol << "[" << curElement->node->weight << "]" << std::endl;
    else
      std::cout << "Internal" << "[" << curElement->node->weight << "]" << std::endl;
    curElement = curElement->next;
  }
}