#include <iostream>
using namespace std;

// Function to print a 2D array
void printArray(int arr[3][3], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to search for an element in the array
bool search(int arr[3][3], int target, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (arr[i][j] == target)
      {
        return true;
      }
    }
  }
  return false;
}

// Function to transpose a matrix
void transpose(int arr[3][3], int result[3][3], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[j][i] = arr[i][j];
    }
  }
}

// Function to sum all elements in the array
int sumArray(int arr[3][3], int rows, int cols)
{
  int sum = 0;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      sum += arr[i][j];
    }
  }
  return sum;
}

// Function to sum elements in a specific row
int sumRow(int arr[3][3], int row, int cols)
{
  int sum = 0;
  for (int j = 0; j < cols; j++)
  {
    sum += arr[row][j];
  }
  return sum;
}

// Function to sum elements in a specific column
int sumColumn(int arr[3][3], int col, int rows)
{
  int sum = 0;
  for (int i = 0; i < rows; i++)
  {
    sum += arr[i][col];
  }
  return sum;
}

// Function to multiply two matrices
void multiplyMatrices(int first[3][3], int second[3][3], int result[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < 3; k++)
      {
        result[i][j] += first[i][k] * second[k][j];
      }
    }
  }
}

int main()
{
  // Initializing a 3x3 array
  int arr[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  // Display the original array
  cout << "Original Array:" << endl;
  printArray(arr, 3, 3);

  // Search for an element
  int target = 5;
  if (search(arr, target, 3, 3))
  {
    cout << "Element " << target << " found in the array!" << endl;
  }
  else
  {
    cout << "Element " << target << " not found in the array." << endl;
  }

  // Update an element (change arr[1][1] to 50)
  arr[1][1] = 50;
  cout << "\nUpdated Array:" << endl;
  printArray(arr, 3, 3);

  // Transpose the matrix
  int transposed[3][3];
  transpose(arr, transposed, 3, 3);
  cout << "\nTransposed Array:" << endl;
  printArray(transposed, 3, 3);

  // Sum of all elements
  int totalSum = sumArray(arr, 3, 3);
  cout << "\nSum of all elements: " << totalSum << endl;

  // Sum of a specific row (row 1)
  int rowSum = sumRow(arr, 1, 3);
  cout << "Sum of row 1: " << rowSum << endl;

  // Sum of a specific column (column 2)
  int colSum = sumColumn(arr, 2, 3);
  cout << "Sum of column 2: " << colSum << endl;

  // Matrix multiplication (multiply arr with itself)
  int result[3][3];
  multiplyMatrices(arr, arr, result);
  cout << "\nMatrix multiplication of arr with itself:" << endl;
  printArray(result, 3, 3);

  return 0;
}
