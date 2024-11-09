#include <iostream>
using namespace std;

int main()
{
  int rows = 3;
  int cols = 3;

  // Dynamically allocating a 2D array
  int **arr = new int *[rows]; // Array of pointers to rows
  for (int i = 0; i < rows; i++)
  {
    arr[i] = new int[cols]; // Allocate memory for each row
  }

  // Initialize the 2D array
  int value = 1;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      arr[i][j] = value++;
    }
  }

  // Display the 2D array
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // Deallocate memory
  for (int i = 0; i < rows; i++)
  {
    delete[] arr[i]; // Delete each row
  }
  delete[] arr; // Delete the array of pointers

  return 0;
}
