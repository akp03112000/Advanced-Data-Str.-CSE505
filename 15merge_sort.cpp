#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sub-arrays
void merge(vector<int> &arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays to hold the left and right sub-arrays
  vector<int> leftArr(n1), rightArr(n2);

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++)
  {
    leftArr[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    rightArr[i] = arr[mid + 1 + i];
  }

  // Merge the temporary arrays back into the original array
  int i = 0;    // Initial index for left sub-array
  int j = 0;    // Initial index for right sub-array
  int k = left; // Initial index for merged sub-array

  while (i < n1 && j < n2)
  {
    if (leftArr[i] <= rightArr[j])
    {
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements of left sub-array if any
  while (i < n1)
  {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy remaining elements of right sub-array if any
  while (j < n2)
  {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

// Merge Sort function to sort the array
void mergeSort(vector<int> &arr, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2; // Find the middle point

    // Recursively sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Function to print the array
void printArray(const vector<int> &arr)
{
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 7};

  cout << "Original array: ";
  printArray(arr);

  // Perform Merge Sort
  mergeSort(arr, 0, arr.size() - 1);

  cout << "Sorted array: ";
  printArray(arr);

  return 0;
}
