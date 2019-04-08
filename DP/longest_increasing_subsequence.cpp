#include <iostream>
#include <memory.h>

using namespace std;

int *arr, *dp;

int main() {
  int n, max = -1;
  cin >> n;
  arr = new int[n];
  dp = new int[n];
  memset(dp, 0x00, n*sizeof(int));
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i]) {
        dp[i] = dp[j] > dp[i] ? dp[j] : dp[i];
      }
    }
    ++dp[i];
    max = max < dp[i] ? dp[i] : max;
  }
  cout << max << endl;
  delete [] arr;
  delete [] dp;
  return 0;
}
