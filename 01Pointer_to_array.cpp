//     Pointer to an Array

#include <iostream>
using namespace std;
int main()
{
  double area[5] = {108.0, 72.0, 65.6, 107.5, 38.0}; // an array with 5 elements.
  double *ptr;

  ptr = area;

  cout << "Array values using pointer " << endl; // Printing each array element's value using pointer

  for (int i = 0; i < 5; i++)
  {
    cout << "Area " << i << " : ";
    cout << *(ptr + i) << endl;
  }
  cout << "Array values using area as address " << endl;

  for (int i = 0; i < 5; i++)
  {
    cout << "Area " << i << " : ";
    cout << *(area + i) << endl;
  }
  return 0;
}
