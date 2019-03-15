#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <memory.h>

using namespace std;

typedef struct {
  int x;
  int y;
  int times;
} Node;

int map[401][401];
int n, m;
int D[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

inline bool isValid(Node n) {
  return n.x > 0 and n.y > 0 and n.x <= ::n and n.y <= m;
}

void bfs(Node no) {
  queue<Node> Q;
  Q.push(no);

  while (not Q.empty()) {
    Node n = Q.front();
    Q.pop();

    if (map[n.x][n.y] != -1) continue;
    map[n.x][n.y] = n.times;

    for (int i = 0; i < 8; ++i) {
      Node tmp = {n.x+D[i][0], n.y+D[i][1], n.times+1};
      if (isValid(tmp)) {
        Q.push(tmp);
      }
    }
  }
}

int main() {
  int x, y;
  cin >> n >> m >> x >> y;
  Node init = {x, y, 0};

  memset(map, -1, sizeof(map));

  bfs(init);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%-5d ", map[i][j]);
    }
    printf("\n");
  }
  return 0;
}
