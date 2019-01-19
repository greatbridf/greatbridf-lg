#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  // 插入排序
  for (int i = 1; i < n; ++i) {
    if (arr[i-1] < arr[i]) continue;
    int tmp = arr[i], j = i;
    while (j > 0 & arr[j-1] > tmp) {
      arr[j] = arr[j-1];
      --j;
    }
    arr[j] = tmp;
  }
  for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  cout << endl;
  delete [] arr;
  return 0;
}
