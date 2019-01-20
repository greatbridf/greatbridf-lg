// 快速排序
#include <iostream>
#include <algorithm>

using namespace std;

void quicksort(int* arr, int left, int right);

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  quicksort(arr, 0, n-1);
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  delete [] arr;
  return 0;
}

void quicksort(int* arr, int left, int right) {
  if (left >= right) return;
  int i = left, j = right, base = arr[left];  // 以最右元素为基准 base = arr[right]
  while (i < j) {
    while (arr[j] >= base && i < j) --j;      // 从基准数相反方向开始调换
    while (arr[i] <= base && i < j) ++i;      // 这两行对调
    if (i < j) swap(arr[i], arr[j]);
  }
  arr[left] = arr[i];                         // arr[right] = arr[i]
  arr[i] = base;
  quicksort(arr, left, i-1);
  quicksort(arr, i+1, right);
}
