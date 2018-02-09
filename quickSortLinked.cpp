#include <iostream>
#include <stack>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
  int value;
  Node* next, *prev;
};


int main()
{
  const int size = 10000;
  Node* Start = 0, *End = 0;
  for (int i = 0; i < size; i++)
  {
    Node* node = new Node;
    node->value = rand() % 200;
    node->next = 0;
    node->prev = End;
    if (End) End->next = node;
    if (!Start) Start = node;
    End = node;
  }

  stack<pair<Node*, Node*> > todo;   
  todo.push(pair<Node*, Node*>(Start, End));    
  while (!todo.empty())
  {
    Node* start = todo.top().first;
    Node* end = todo.top().second;
    todo.pop();
    if (start == end) continue;
    if (start->prev == end) continue;
      
    Node* pivot = start;
    Node* left = start;
    Node* right = end;
    while (true)
    {
      while (left != pivot && left->value <= pivot->value) left = left->next;
      while (pivot != right && pivot->value <= right->value) right = right->prev;
      if (left == right)
      {
        todo.push(pair<Node*, Node*>(start, pivot->prev));    
        todo.push(pair<Node*, Node*>(pivot->next, end));    
        break;
      }
      else if (left == pivot)
      {
        swap(pivot->value, right->value);
        pivot = right;
        left = left->next;
      }
      else if (pivot == right)
      {
        swap(left->value, pivot->value);
        pivot = left;
        right = right->prev;
      }
      else
      {
        swap(left->value, right->value);
        left = left->next;
        right = right->prev;
  } } }

  for (Node* p = Start; p; p = p->next) cout << p->value << ' ';
  cout << endl;
}