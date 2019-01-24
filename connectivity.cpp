#include <iostream>
#include <memory.h>

using namespace std;

int g[1000][1000];
bool visited[1000] = {false};
int n, m;
int conn;

void dfs(int start) {
  visited[start] = true;
  ++conn;
  if (conn == n)
    return;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i] && g[start][i]) {
      dfs(i);
    }
  }
  return;
}

int main() {
  int u, v;
  while (cin >> n >> m) {
    conn = 0;
    memset(g, 0x00, sizeof(g));
    memset(visited, 0x00, sizeof(visited));
    for (int i = 1; i <= m; ++i) {
      cin >> u >> v;
      g[u][v] = 1;
      g[v][u] = 1;
    }
    dfs(1);
    if (conn == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

