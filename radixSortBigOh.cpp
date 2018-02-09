#include <iostream> // for cout and endl
#include <list> // for string
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{
  // problem setup goes here

  // programmer customizations go here
  int n = 100000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
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
    
    for (int place = 0; ; place++) // units, tens, hundreds,...
    {
      // place values in bins  
      list<int> bins[10]; // bins for digits 0-9
      for (int i = 0; i < n; i++)
      {
        int bin = a[i]; // find the bin for this place's digit
        for (int j = 0; j < place; j++) bin /= 10;
        bin %= 10; // this is the bin number
        bins[bin].push_back(a[i]); 
      }
      
      // place values from bins back into array  
      int index = 0;
      for (int i = 0; i < 10; i++)
        for (auto it = bins[i].begin(); it != bins[i].end(); it++)
          a[index++] = *it;
      
      // see if we're done  
      int binsInUse = 0;
      for (int i = 0; i < 10; i++)
        binsInUse += !bins[i].empty();
      if (binsInUse == 1) break;
    }

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
