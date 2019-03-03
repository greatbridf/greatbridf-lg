#include <iostream>
#include <memory.h>

using namespace std;

int arr[1001] = {};

int calc(int n) {
  if (arr[n] != -1)
    return arr[n];
  for (int i = 1; i <= n/2; ++i) {
    arr[n] += calc(i);
  }
  return arr[n];
}

int main() {
  memset(arr, -1, sizeof(arr));
  int n;
  cin >> n;
  cout << calc(n);
  return 0;
}
