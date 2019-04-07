#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

typedef struct {
  int x;
  int y;
} Node;

bool map[101][101];
int X, Y;

int D[8][2] = { {1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1} };

void bfs(int x, int y) {
  map[x][y] = false;
  queue<Node> qu;
  Node start;
  start.x = x;
  start.y = y;
  qu.push(start);

  Node n, tmp;
  while (!qu.empty()) {
    n = qu.front();
    qu.pop();

    for (int i = 0; i < 8; ++i) {
      tmp.x = n.x+D[i][0];
      tmp.y = n.y+D[i][1];
      if (tmp.x <= 0 or tmp.x > Y or tmp.y <= 0 or tmp.y > X)
        continue;
      if (map[tmp.x][tmp.y]) {
        map[tmp.x][tmp.y] = false;
        qu.push(tmp);
      }
    }
  }
}

int main() {
  cin >> Y >> X;
  char tmp = 0x00;
  for (int i = 1; i <= Y; ++i) {
    for (int j = 1; j <= X; ++j) {
      cin >> tmp;
      if (tmp == '#') {
        map[i][j] = true;
      }
    }
  }
  int result = 0;
  for (int i = 1; i <= Y; ++i) {
    for (int j = 1; j <= X; ++j) {
      if (map[i][j]) {
        ++result;
        bfs(i, j);
      }
    }
  }
  cout << result;
  return 0;
}
