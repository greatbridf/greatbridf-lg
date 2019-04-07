#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool map[9][9];
bool zong[9];

int result = 0;

void dfs(int n, int k, int curr) {
  if (k == 0) {
    ++result;
  }
  for (int i = curr; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (map[i][j] && !zong[j]) {
        zong[j] = true;
        dfs(n, k-1, i+1);  // Search from the next line
        zong[j] = false;
      }
    }
  }
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    result = 0;
    char tmp = 0x00;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> tmp;
        if (tmp == '#') {
          map[i][j] = true;
        }
      }
    }
    dfs(n, k, 1);
    cout << result << endl;
    memset(map, 0x00, sizeof(map));
  }
  return 0;
}
