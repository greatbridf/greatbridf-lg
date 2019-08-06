#include <iostream>

using namespace std;

void dfs(int n) {
  if (结束的条件) {
    // 记录 输出
    return;
  }
  for (int i = n; i < hang; ++i) {
    if (有没有棋子) {
      a[x][y] = 1;
      dfs(n+1);
      a[x][y] = 0;
    }
  }
}

1 0 0
0 1 0
1 0 1
