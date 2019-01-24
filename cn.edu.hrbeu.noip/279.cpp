#include <iostream>

using namespace std;

int result[11];

int m, limit;

int sum = 0, result_count = 0;

int debug = 0;

void dfs(int fir) {
  if (sum == m) {
    cout << result[0];
    for (int i = 1; i < result_count; ++i) {
      cout << "+" << result[i];
    }
    cout << endl;
    return;
  }
  for (int i = 1; i < m; ++i) {
    if (sum < m && (result_count == 0 || result[result_count-1] <= i)) {
      result[result_count] = i;
      sum += i;
      ++result_count;
      dfs(fir+1);
      --result_count;
      sum -= i;
      result[result_count] = 0;
    }
  }
}

int main() {
  while (cin >> m) {
    limit = m / 2;
    dfs(1);
  }
  return 0;
}
