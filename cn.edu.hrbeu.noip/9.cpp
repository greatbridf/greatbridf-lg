// http://noip.hrbeu.edu.cn/problem/9
#include <iostream>
#include <memory.h>

using namespace std;

const int amounts[] = {100, 50, 20, 10, 5, 2, 1};

void change(int* arr, int& total, int amount);

int main() {
  int n = 0;
  int result[7] = {};
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      int tmp = 0;
      cin >> tmp;
      change(result, tmp, 0);
    }
    for (int i = 0; i < 7; ++i)
      cout << result[i] << " ";
    cout << endl;
    memset(result, 0x00, 7*sizeof(int));
  }
  return 0;
}

void change(int* arr, int& total, int amount_Index) {
  int satsu = total / amounts[amount_Index];
  total -= (amounts[amount_Index] * satsu);
  arr[amount_Index] += satsu;
  if (amount_Index != 6)
    change(arr, total, ++amount_Index);
}
