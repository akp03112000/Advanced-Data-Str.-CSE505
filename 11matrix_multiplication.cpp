#include <iostream>
using namespace std;

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
  int first[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  int second[3][3] = {
      {9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}};
  int result[3][3];

  multiplyMatrices(first, second, result);

  cout << "Product of matrices:" << endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
