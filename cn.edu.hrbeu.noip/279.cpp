// Figure out what's fuckin' going on there
#include <iostream>

using namespace std;

int result[11];

int m, sum = 0;

void dfs(int n) {
  if (sum == m) {
    cout << result[0];
    for (int i = 1; i < n-1; ++i) {
      cout << "+" << result[i];
    }
    cout << endl;
    return;
  }
  for (int i = 1; i < m; ++i) {
    if (sum < m && (n == 1 || result[n-2] <= i)) {
      result[n-1] = i;
      sum += i;
      dfs(n+1);
      sum -= i;
      result[n-1] = 0;
    }
  }
}

int main() {
  while (cin >> m) {
    dfs(1);
  }
  return 0;
}
