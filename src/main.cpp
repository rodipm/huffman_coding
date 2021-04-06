#include <iostream>
#include "PriorityQueue.cpp"

/* Node tree[128]; */

int main()
{
  Node* n1 = new Node();
  n1->symbol = 'a';
  n1->weight = 2;
  n1->parent = nullptr;

  PriorityQueue pq;

  pq.push(n1);


  /* Node n2; */
  /* n2.symbol = 'b'; */
  /* n2.weight = 1; */
  /* n2.parent = &n1; */

  return 0;
}
