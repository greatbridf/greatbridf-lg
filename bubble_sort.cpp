#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  // sort
  for (int i = 0; i < n-1; ++i) {
    bool flag = false;
    for (int j = 0; j < n-1-i; ++j) {
      if (arr[j] > arr[j+1]) {    // 将相对大（小）的值后移
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
        flag = true;
      }
    }
    if (!flag) break;   // 如果已经排好序直接返回
  }
  for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  cout << endl;
  delete [] arr;
  return 0;
}
