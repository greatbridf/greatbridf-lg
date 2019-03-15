#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

bool map[1001][1001];
int* red[1001][1001];
int m, n;

class Node {
public:
  int x, y;
  Node(int x, int y) : x(x), y(y) {};
};

int D[4][2] = {
  {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

inline bool isValid(Node n) {
  return not (n.x < 1 or n.y < 1 or n.x > ::n or n.y > ::n);
}

int bfs(Node no) {
  if (red[no.x][no.y])
    return *red[no.x][no.y];
  red[no.x][no.y] = new int;
  int result = 0;
  queue<Node> Q;
  Q.push(no);

  while (not Q.empty()) {
    Node n = Q.front();
    Q.pop();

    if (not(n.x == no.x and n.y == no.y) and red[n.x][n.y])
      continue;
    red[n.x][n.y] = red[no.x][no.y];
    ++result;

    for (int i = 0; i < 4; ++i) {
      Node tmp = Node(n.x+D[i][0], n.y+D[i][1]);
      if (isValid(tmp) and not red[tmp.x][tmp.y] and map[tmp.x][tmp.y] != map[n.x][n.y]) {
        Q.push(tmp);
      }
    }
  }
  *red[no.x][no.y] = result;
  return result;
}

int main() {
  cin >> n >> m;
  char c = 0;
  int x = 0, y = 0;
  // Read in optimize
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      while ((c = getchar()) != '0' and c != '1');
      map[i][j] = c - '0';
    }
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    printf("%d\n", bfs(Node(x, y)));
  }

  return 0;
}
