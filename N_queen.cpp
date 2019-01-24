#include <iostream>

bool vis[8][8];
bool col[8] = {};      // 列
bool pos[15] = {};     // 正对角线
bool opp[15] = {};     // 反对角线

int count = 0;
int n;

void dfs(int i) {
  if (i == n) {
    // 输出
    // for (int m = 0; m < n; ++m) {
    //   for (int k = 0; k < n; ++k) {
    //     if (vis[m][k])
    //       std::cout << m << "," << k << " ";
    //   }
    // }
    // std::cout << std::endl;
    ++count;
    return;
  }
  for (int j = 0; j < n; ++j) {
    if (!col[j] && !pos[i+j] && !opp[i-j+7]) {
      vis[i][j] = true;
      col[j] = true;      // 第j列放置
      pos[i+j] = true;    // 第i+j条正对角线放置
      opp[i-j+7] = true;  // 第i-j+7条反对角线放置（i-j+7防止下标出现负数）
      dfs(i+1);           // 递归放置下一个皇后
      vis[i][j] = false;
      col[j] = false;     // 清除
      pos[i+j] = false;
      opp[i-j+7] = false;
    }
  }
}

int main() {
  n = 8;
  dfs(0);
  std::cout << count << std::endl;
  return 0;
}
