#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
  int largest = i;       // Initialize largest as root
  int left = 2 * i + 1;  // Left child
  int right = 2 * i + 2; // Right child

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }

  // If right child is larger than the largest so far
  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  // If largest is not root, swap it with the largest element
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    // Recursively heapify the affected subtree
    heapify(arr, n, largest);
  }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
  // Build a max heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  // Extract elements from the heap one by one
  for (int i = n - 1; i >= 1; i--)
  {
    // Move current root (maximum) to the end
    swap(arr[0], arr[i]);

    // Call heapify on the reduced heap
    heapify(arr, i, 0);
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
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  printArray(arr, n);

  // Perform Heap Sort
  heapSort(arr, n);

  cout << "Sorted array: ";
  printArray(arr, n);

  return 0;
}
