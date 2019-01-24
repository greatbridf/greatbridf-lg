#include <iostream>

using namespace std;

int img[6][6] = {{0, 0, 0, 0, 0, 0},
                 {0, 0, 1, 1, 0, 1},
                 {0, 1, 0, 1, 0, 1},
                 {0, 1, 1, 0, 1, 1},
                 {0, 0, 0, 1, 0, 1},
                 {0, 1, 1, 1, 1, 0}
                };

int result[9];

void dfs(int n, int m) {
  result[m] = n;
  if (m == 8) {
    for (int i = 0; i < 9; ++i) {
      cout << result[i];
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= 5; ++i) {
    if (img[n][i] && img[i][n]) {
      img[n][i] = 0;
      img[i][n] = 0;
      dfs(i, m+1);
      img[n][i] = 1;
      img[i][n] = 1;
    }
  }
}

int main() {
  dfs(1, 0);
  return 0;
}

