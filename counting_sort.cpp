#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  cin >> arr[0];
  int max = arr[0], min = arr[0];
  for (int i = 1; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
  }
  int* result = new int[max - min + 1];
  for (int i = 0; i < n; ++i)
    ++result[arr[i]-min];
  for (int i = 0; i < (max - min + 1); ++i)
    while (result[i]--)
      cout << i+min << " ";
  delete [] result;
  return 0;
}
