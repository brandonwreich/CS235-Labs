#include <iostream>
#include <vector>
#include <stdlib.h>
#include <array>
using namespace std;

int main()
{
  int numbers[] = {23, 14, 65, 3, 19, 2, 71, 12, 8, 61, 5, 25};
  int index = 0;

  for (int i = 0; i < 9; i++)
  {
    int min = numbers[i];

    for (int j = i + 1; j < 9 - i; j++)
    {
      if (numbers[j] < min)
      {
        int temp = numbers[i];

        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }
  }

  for (int y = 0; y < 11; y++)
  {
    cout << numbers[y] << " ";
  }
}
