#include <iostream>

using namespace std;

int main() {
  int n = 0, sum = 0, avg = 0;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }
  avg = sum / n;
  for (int i = 0; i < n; ++i) arr[i] -= avg;
  int result = 0;
  for (int i = 0; i < n; ++i) {   // -1 -2 3 10 -4 -6
    if (arr[i] == 0) continue;
    arr[i+1] += arr[i];
    ++result;
  }
  cout << result;
  delete [] arr;
  return 0;
}
