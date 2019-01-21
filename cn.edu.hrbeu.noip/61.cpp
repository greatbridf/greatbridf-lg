#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n-1; ++j) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        ++result;
      }
    }
  }
  cout << result;
  delete [] arr;
  return 0;
}
