#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum element from the array
int getMax(const vector<int> &arr)
{
  return *max_element(arr.begin(), arr.end());
}

// Counting sort based on the digit represented by exp (10^i where i is the current digit)
void countingSort(vector<int> &arr, int exp)
{
  int n = arr.size();
  vector<int> output(n);    // Output array
  vector<int> count(10, 0); // Count array to store count of occurrences of digits

  // Store count of occurrences of (arr[i] / exp) % 10
  for (int i = 0; i < n; i++)
  {
    count[(arr[i] / exp) % 10]++;
  }

  // Change count[i] so that count[i] contains the actual position of this digit in output[]
  for (int i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (int i = n - 1; i >= 0; i--)
  {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // Copy the sorted numbers into the original array
  for (int i = 0; i < n; i++)
  {
    arr[i] = output[i];
  }
}

// Radix Sort function to implement LSD (Least Significant Digit first)
void radixSort(vector<int> &arr)
{
  int max = getMax(arr); // Find the maximum number to know the number of digits

  // Do counting sort for every digit. The exp is 10^i where i is the current digit number
  for (int exp = 1; max / exp > 0; exp *= 10)
  {
    countingSort(arr, exp);
  }
}

int main()
{
  vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

  cout << "Original array: ";
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;

  // Perform Radix Sort
  radixSort(arr);

  cout << "Sorted array: ";
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
