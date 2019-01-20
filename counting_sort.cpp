#include <iostream>

using namespace std;

int main() {
  int n = 0, max = -1, min = 2147483647;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    int tmp = 0;
    cin >> tmp;
    arr[i] = tmp;
    if (tmp > max) max = tmp;
    if (tmp < min) min = tmp;
  }
  int* sorted = new int[max - min + 1];
  for (int i = 0; i < n; ++i) {
    ++sorted[arr[i] - min];
  }
  for (int i = 0; i < (max - min + 1); ++i) {
    while (sorted[i]--) {
      cout << i + min << " ";
    }
  }
  delete [] arr;
  delete [] sorted;
  return 0;
}
