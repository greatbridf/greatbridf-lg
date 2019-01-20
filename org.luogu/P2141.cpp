// Failed tests
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  short n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", arr+i);
  sort(arr, arr+n);
  int result = 0;
  int groupings = (n-1)*(n-2)/2;
  int* sums = new int[groupings];
  int sum_index = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j) {
      sums[sum_index] = arr[i] + arr[j];
      ++sum_index;
    }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < groupings; ++j)
      if (sums[j] == arr[i]) ++result;
  }
  printf("%d", result);
  delete [] sums;
  return 0;
}
