#include <iostream>
#include <string>

using namespace std;

int g[6][6] = {
  {0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 1},
  {0, 1, 0, 1, 0, 1},
  {0, 1, 1, 0, 1, 1},
  {0, 0, 0, 1, 0, 1},
  {0, 1, 1, 1, 1, 0}
};

int ans[9] = {1, 0};

void dfs(int cur, int step) {
  if (step == 9) {
    for (int i = 0; i < 9; ++i) {
      cout << ans[i];
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= 5; ++i) {
    if (g[cur][i] && g[i][cur]) {
      g[cur][i] = 0;
      g[i][cur] = 0;
      ans[step] = i;
      dfs(i, step+1);
      g[i][cur] = 1;
      g[cur][i] = 1;
    }
  }
  return;
}

int main() {
  dfs(1, 1);
  return 0;
}
