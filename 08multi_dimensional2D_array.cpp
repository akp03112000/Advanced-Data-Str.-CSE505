#include <iostream>
using namespace std;

int main()
{
  // Declare and initialize a 2D array (3 rows and 3 columns)
  int arr[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  // Accessing elements of the 2D array
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << arr[i][j] << " "; // Print each element in row-major order
    }
    cout << endl;
  }

  return 0;
}
