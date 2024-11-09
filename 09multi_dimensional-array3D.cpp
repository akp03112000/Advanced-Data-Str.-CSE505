#include <iostream>
using namespace std;

int main()
{
  // Declare and initialize a 3D array (2 blocks, 3 rows, and 3 columns)
  int arr[2][3][3] = {
      {{1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}},
      {{10, 11, 12},
       {13, 14, 15},
       {16, 17, 18}}};

  // Accessing elements of the 3D array
  for (int i = 0; i < 2; i++)
  { // Loop through blocks
    for (int j = 0; j < 3; j++)
    { // Loop through rows
      for (int k = 0; k < 3; k++)
      {                              // Loop through columns
        cout << arr[i][j][k] << " "; // Print each element
      }
      cout << endl;
    }
    cout << endl; // Separate blocks with a blank line
  }

  return 0;
}
