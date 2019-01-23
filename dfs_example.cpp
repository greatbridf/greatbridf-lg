#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

bool visited[9];
int result[9];

void dfs(int end_sign, int n) {
  if (n > end_sign) {
    for (int i = 0; i < end_sign; ++i)
      printf("%d ", result[i]);
    cout << endl;
    return;
  }
  for (int i = 0; i < end_sign; ++i) {
    if (!visited[i]) {
      visited[i] = true;
      result[n-1] = i+1;
      dfs(end_sign, n+1);
      visited[i] = false;
    }
  }
}

int main() {
  int sign;
  while (cin >> sign) {
    memset(visited, 0x00, sizeof(visited));
    dfs(sign, 1);
  }
  return 0;
}

