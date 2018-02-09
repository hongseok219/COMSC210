#include <list>
#include <iostream>
using namespace std;

#include <cstdlib>

int main()
{
  const int size = 100000;
  int a[size];
  for (int i = 0; i < size; i++) a[i] = rand() % 200;

  for (int place = 0; ; place++) // units, tens, hundreds,...
  {
    // place values in bins  
    list<int> bins[10]; // bins for digits 0-9
    for (int i = 0; i < size; i++)
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

  for (int i = 0; i < size; i++) cout << a[i] << ' ';
  cout << endl;
}