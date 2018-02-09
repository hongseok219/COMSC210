#include <iostream>
#include <stack>
#include <utility>
using namespace std;

#include <cstdlib>

int main()
{
  const int size = 10000;
  int a[size];
  for (int i = 0; i < size; i++) a[i] = rand() % 200;
    
  stack<pair<int, int> > todo;   
  todo.push(pair<int, int>(0, size));    
  while (!todo.empty())
  {
    int start = todo.top().first;
    int end = todo.top().second;
    todo.pop();
    if (start >= end) continue;
      
    int pivot = (start + end - 1) / 2;
    int left = start;
    int right = end - 1;
    while (true)
    {
      while (left < pivot && a[left] <= a[pivot]) left++;
      while (pivot < right && a[pivot] <= a[right]) right--;
      if (left == right)
      {
        todo.push(pair<int, int>(start, pivot));    
        todo.push(pair<int, int>(pivot + 1, end));    
        break;
      }
      else if (left == pivot)
      {
        swap(a[pivot], a[right]);
        pivot = right;
        left++;
      }
      else if (pivot == right)
      {
        swap(a[left], a[pivot]);
        pivot = left;
        right--;
      }
      else
      {
        swap(a[left], a[right]);
        left++;
        right--;
  } } }

  for (int i = 0; i < size; i++) cout << a[i] << ' ';
  cout << endl;
}