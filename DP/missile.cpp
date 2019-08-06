#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int arr[100000], dp[100000];
int tmp = 0;

int bfs(int n) {
  memset(dp, 0x00, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] >= arr[i]) {
        dp[i] = (dp[i] > dp[j] ? dp[i] : dp[j]);
      }
    }
    ++dp[i];
  }
  // DEBUG
  cout << endl << "[DEBUG]: ";
  for (int i = 0; i < n; ++i) {
    printf("%d ", dp[i]);
  }
  cout << endl;
  // DEBUG
  int max = dp[n-1];
  for (int i = n-2; i >= 0; --i)
    max = max < dp[n] ? dp[n] : max;
  return max;
}

int main() {
  int n = 0;
  while (scanf("%d", arr+(n++)) != EOF) { } --n;
  int first = bfs(n), second = 1;
  tmp = first;
  cout << first << endl;
  if (first == n) {
    cout << second;
    return 0;
  }
  while (true) {
    for (int i = n, num = tmp; num > 0 and i >= 0; --i) {
      if (dp[i] == num) {
        arr[i] = -1;
        --num;
      }
    }
    for (int i = 0, j = 0; i < n; ++i) {
      if (arr[i] != -1) {
        arr[j] = arr[i];
        ++j;
      }
    }
    n -= tmp;
    ++second;
    tmp = bfs(n);
    if (tmp == n)
      break;
  }
  cout << second;
  return 0;
}
