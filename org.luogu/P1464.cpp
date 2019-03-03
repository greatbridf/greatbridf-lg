#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

long long arr[21][21][21];

long long func(long long a, long long b, long long c) {
  if (a <= 0 or b <= 0 or c <= 0) return 1;
  if (a > 20 or b > 20 or c > 20) return func(20, 20, 20);
  if (a < b and b < c) return arr[a][b][c] == -1 ? arr[a][b][c] = func(a, b, c-1) + func(a, b-1, c-1) - func(a, b-1, c) : arr[a][b][c];
  return arr[a][b][c] == -1 ? arr[a][b][c] = func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1) : arr[a][b][c];
}

int main() {
  long long a, b, c;
  while (cin >> a >> b >> c) {
    if (a == -1 and b == -1 and c == -1) break;
    memset(arr, -1, sizeof(arr));
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, func(a, b, c));
  }
  return 0;
}
