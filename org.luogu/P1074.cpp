#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long maxscore = -1;

typedef struct Test {
  int count;
  int line;
} Test;

bool cmp(Test a, Test b) {
  return a.count > b.count;
}

Test order[9];
int head = 0;
char map[9][9];
/*
 * x y y y y y y y y y y
 * x
 * x
 * x
 * x
 * x
 * x
 * x
 * x
 */
bool heng[9][9];
bool shu[9][9];
bool blk[3][3][9];

void dfs(int x, int y) {
  if (y == 9) {
    if (x == order[8].line) {
      //printf("Find a solution!\nx=%d, y=%d\n", x, y);
      //for (int i = 0; i < 9;  ++i) {
      //  for (int j = 0; j < 9; ++j) {
      //    printf("%d ", map[i][j]);
      //  }
      //  printf("\n");
      //}
      //printf("---------\n");

      long long score = 0;
      long long tmp = 0;
      // Center point
      score += (map[4][4] * 10);

      // Out loop
      for (int i = 0; i < 9; ++i) {
        if (i == 0 or i == 8) {
          for (int j = 0; j < 9; ++j) {
            tmp += map[i][j];
          }
        } else {
          tmp += map[i][0] + map[i][8];
        }
      }
      score += (tmp * 6);
      tmp = 0;

      // Semi-out loop
      for (int i = 1; i < 8; ++i) {
        if (i == 1 or i == 7) {
          for (int j = 1; j < 8; ++j) {
            tmp += map[i][j];
          }
        } else {
          tmp += map[i][1] + map[i][7];
        }
      }
      score += (tmp * 7);
      tmp = 0;

      // Secondary loop
      for (int i = 2; i < 7; ++i) {
        if (i == 2 or i == 6) {
          for (int j = 2; j < 7; ++j) {
            tmp += map[i][j];
          }
        } else {
          tmp += map[i][2] + map[i][6];
        }
      }
      score += (tmp * 8);
      tmp = 0;

      // Primary loop
      for (int i = 3; i < 6; ++i) {
        if (i == 4) {
          tmp += map[i][3] + map[i][5];
        } else {
          for (int j = 3; j < 6; ++j) {
            tmp += map[i][j];
          }
        }
      }
      score += (tmp * 9);

      if (score > maxscore) {
        maxscore = score;
        return;
      }
    } else {
      dfs(order[++head].line, 0);
      --head;
    }
  }
  if (map[x][y]) {
    dfs(x, y+1);
    return;
  }
  for (char i = 1; i <= 9; ++i) {
    if (not heng[x][i] and not shu[y][i] and not blk[x/3][y/3][i]) {
      map[x][y] = i;
      heng[x][i] = true;
      shu[y][i] = true;
      blk[x/3][y/3][i] = true;
      dfs(x, y+1);
      heng[x][i] = false;
      shu[y][i] = false;
      blk[x/3][y/3][i] = false;
      map[x][y] = 0;
    }
  }
}

int main() {
  int tmp = 0x00;
  for (register int i = 0; i < 9; ++i) {
    order[i].line = i;
    for (register int j = 0; j < 9; ++j) {
      scanf("%d", &tmp);
      if (tmp) {
        heng[i][tmp] = true;
        shu[j][tmp] = true;
        blk[i/3][j/3][tmp] = true;
        ++(order[i].count);
      }
      map[i][j] = tmp;
    }
  }
  sort(order, order+9, cmp);
  dfs(order[0].line, 0);
  cout << maxscore;
  return 0;
}
