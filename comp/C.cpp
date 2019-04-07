// Deprecated
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int arr[100];

int main() {
  int n;
  cin >> n;
  while (n--) {
    memset(arr, 0x00, sizeof(arr));
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      scanf("%d", arr+i);
    }
    sort(arr, arr+m);
    for (int i = m-1; i >= 0; --i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] % arr[j] == 0) --m;
      }
    }
    cout << m;
  }
  return 0;
}
