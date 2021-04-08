#ifndef CREATED_NODE_LIST
#define CREATED_NODE_LIST

#include <iostream>
#include "Node.cpp"
struct CreatedNodeElement
{
  Node *node;
  CreatedNodeElement *next;
};

struct CreatedNodeList
{
  CreatedNodeElement *createdNodeList = nullptr;

  void push(Node *node)
  {
    CreatedNodeElement *newNodeElement = new CreatedNodeElement();
    newNodeElement->node = node;
    newNodeElement->next = nullptr;
    if (createdNodeList == nullptr)
    {
      createdNodeList = newNodeElement;
    }
    else
    {
      CreatedNodeElement *curNodeElement = createdNodeList;

      while (curNodeElement->next != nullptr)
      {
        curNodeElement = curNodeElement->next;
      }

      curNodeElement->next = newNodeElement;
    }
  }

  void print()
  {
    CreatedNodeElement *curElement = createdNodeList;

    while (curElement != nullptr)
    {
      std::cout << "CreatedNodeElement: " << curElement->node->symbol << "[" << curElement->node->weight << "]" << std::endl;
      curElement = curElement->next;
    }
  }

  void clean()
  {
    if (createdNodeList == nullptr)
      return;

    CreatedNodeElement *curElement = createdNodeList;
    CreatedNodeElement *nextElement;

    while (curElement != nullptr)
    {
      delete curElement->node;
      nextElement = curElement->next;
      delete curElement;
      curElement = nextElement;
    }
    this->createdNodeList = nullptr;
  }
};

#endif