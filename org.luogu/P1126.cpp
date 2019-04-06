// TODO
#include <iostream>
#include <queue>
#include <cstdio>

typedef struct {
  int x;
  int y;
  char facing;
  int result;
} Node;

bool map[51][51];
int vis[51][51];

int n, m;   // m: cols, n: lines
Node start, end;

int bfs() {
  std::queue<Node> Q;
  Q.push(start);

  while (not Q.empty()) {
    Node tmp = Q.front();
    Q.pop();

    if (tmp.x < 0 or tmp.y < 0 or tmp.x > m or tmp.y > n or map[tmp.x][tmp.y])
      continue;

    if (tmp.x == end.x and tmp.y == end.y) {
      return tmp.result;
    }
  }
  return -1;
}

int main() {
  std::cin >> n >> m;
  int tmp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &tmp);
      if (tmp) {
        map[j][i] = true;
        map[j+1][i] = true;
        map[j+1][i+1] = true;
        map[j][i+1] = true;
      }
    }
  }
  for (int i = 0; i <= n+1; ++i) {
    if (i == 0 or i == n+1) {
      for (int j = 0; j <= m+1; ++j) {
        map[j][i] = 1;
      }
    } else {
      map[0][i] = 1;
      map[m+1][i] = 1;
    }
  }
  std::cout << std::endl;
  for (int i = 0; i <= n+1; ++i) {
    for (int j = 0; j <= m+1; ++j) {
      if (map[j][i])
        printf("1 ");
      else
        printf("0 ");
    }
    printf("\n");
  }
  std::cin >> start.x >> start.y >> end.x >> end.y >> start.facing;
  return 0;
  std::cin >> start.x >> start.y >> end.x >> end.y >> start.facing;
  std::cout << bfs();
  return 0;
}

