#include <algorithm>
#include <iostream>
using namespace std;

#include <cstdlib>

int main()
{
  const int size = 100000;
  int a[size];
  for (int i = 0; i < size; i++) a[i] = rand() % 200;

  for (int i = 1; i < size; i++)
  {  
    for (int index = i;;)
    {
      int parentIndex = (index + 1) / 2 - 1;
      if (parentIndex < 0) break;
      if (a[parentIndex] >= a[index]) break;
      swap(a[parentIndex], a[index]);
      index = parentIndex;    
  } }
    
  for (int index = size - 1; index > 0; index--)
  {
    swap(a[0], a[index]);
    int parentIndex = 0; 
    while (true)
    {
      int leftChildIndex = 2 * parentIndex + 1;
      int rightChildIndex = 2 * parentIndex + 2;
      if (leftChildIndex >= index) break; // leaf at parentIndex
      if (rightChildIndex >= index) // one-child for parentIndex
      {
          if (a[leftChildIndex] <= a[parentIndex]) break;
          swap(a[leftChildIndex], a[parentIndex]);
          parentIndex = leftChildIndex;
        }
        else if (a[rightChildIndex] < a[leftChildIndex])
        {
          if (a[leftChildIndex] <= a[parentIndex]) break;
          swap(a[leftChildIndex], a[parentIndex]);
          parentIndex = leftChildIndex;
        }
        else
        {
          if (a[rightChildIndex] <= a[parentIndex]) break;
          swap(a[rightChildIndex], a[parentIndex]);
          parentIndex = rightChildIndex;
    } } }
  cout << endl;

  for (int i = 0; i < size; i++) cout << a[i] << ' ';
  cout << endl;
}