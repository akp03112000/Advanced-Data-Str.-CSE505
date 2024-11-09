#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Partition function to place the pivot element at its correct position
int partition(int arr[], int low, int high)
{
  // Choose the pivot (using last element as pivot here)
  int pivot = arr[high];
  int i = low - 1; // Index of smaller element

  // Re-arrange elements around the pivot
  for (int j = low; j <= high - 1; j++)
  {
    // If the current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // Increment the index of smaller element
      swap(arr[i], arr[j]);
    }
  }
  // Place the pivot element in its correct position
  swap(arr[i + 1], arr[high]);
  return (i + 1); // Return the index of the pivot element
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    // Partition the array and get the pivot index
    int pi = partition(arr, low, high);

    // Recursively apply quick sort on the left and right sub-arrays
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to print the array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  printArray(arr, n);

  // Perform Quick Sort
  quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  printArray(arr, n);

  return 0;
}
