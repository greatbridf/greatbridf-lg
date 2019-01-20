#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned char Byte;

int main() {
  int n;
  cin >> n;
  Byte* arr = new Byte[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  return 0;
}
