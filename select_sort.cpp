// 选择排序
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  // sort
  for (int i = 0; i < n-1; ++i) {
    int minIndex = i;
    for (int j = i+1; j < n; ++j) // 找出最大（小）值
      if (arr[j] < arr[minIndex]) minIndex = j;
    if (minIndex != i) {    // 将最大（小）值与第i个调换
      int tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
  for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  cout << endl;
  delete [] arr;
  return 0;
}
