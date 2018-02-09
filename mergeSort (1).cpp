#include <iostream>
using namespace std;

#include <cstdlib>

int main()
{
  const int size = 100000;
  int a[size];
  for (int i = 0; i < size; i++) a[i] = rand() % 200;
    
  int* temp = new int[size];
  for (int delta = 1; delta < size; delta *= 2)
  {
    int index = 0;
    for (int i = 0; i < size; i++) temp[i] = a[i]; 
    for (int i = 0; i < size; i += 2 * delta)
    {
      int left = i;
      int leftMax = min(left + delta, size);
      int right = leftMax;
      int rightMax = min(right + delta, size);       
      while (true)
      {
        if (left == leftMax && right == rightMax) break;
        if (left == leftMax) a[index++] = temp[right++];
        else if (right == rightMax) a[index++] = temp[left++];
        else if (temp[right] < temp[left]) a[index++] = temp[right++];
        else a[index++] = temp[left++];
      }
    }
  }
  delete [] temp;
    
  for (int i = 0; i < size; i++) cout << a[i] << ' ';
  cout << endl;
}