#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{
  // problem setup goes here

  // programmer customizations go here
  int n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    int* a = new int[n];
    for (int i = 0; i < n; i++) a[i] = rand() % 200;

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    for (int i = 1; i < n; i++)
      for (int index = i;;)
      {
        int parentIndex = (index + 1) / 2 - 1;
        if (parentIndex < 0) break;
        if (a[parentIndex] >= a[index]) break;
        swap(a[parentIndex], a[index]);
        index = parentIndex;    
      } 

    for (int index = n - 1; index > 0; index--)
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

    clock_t endTime = clock(); 
    delete a;
      
    // validation block -- assure that process worked if applicable

    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
} }
