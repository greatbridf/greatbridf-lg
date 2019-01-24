#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n = 0;
bool visited[21] = {false, true, false};
int result[21] = {0, 1, 0};

bool is_prime(int a) {
  if (a <= 3) return true;
  for (int i = 2; i <= sqrt(a); ++i) {
    if (a%i == 0)
      return false;
  }
  return true;
}

void dfs(int step) {
  if (step == n+1 && is_prime(result[step-1]+result[1])) {
    for (int i = 1; i <= n; ++i)
      cout << result[i] << " ";
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!visited[i] && is_prime(i+result[step-1])) {
      visited[i] = true;
      result[step] = i;
      dfs(step+1);
      visited[i] = false;
    }
  }
}

int main() {
  while (cin >> n) {
    dfs(2);
  }
  return 0;
}
