#include <iostream>
#include <queue>

using namespace std;

int Nd[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n;
short map[30][30];
bool vis[30][30];

class Node {
public:
  int x, y;
  short& pos;
  bool& vis;
  Node(int x, int y);
};

Node::Node(int x, int y) : x(x), y(y), pos(map[x][y]), vis(::vis[x][y]) {}

bool isNotValid(Node nc) {
  return nc.x < 0 or nc.x >= n or nc.y < 0 or nc.y >= n;
}

void bfs(int x, int y) {
  queue<Node> Q;
  Q.push(Node(x, y));

  while (not Q.empty()) {
    Node nc = Q.front();
    Q.pop();

    if (isNotValid(nc) or nc.vis or nc.pos != 0) continue;
    nc.vis = true;

    for (int i = 0; i < 4; ++i) {
      Q.push(Node(nc.x+Nd[i][0], nc.y+Nd[i][1]));
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> map[i][j];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 or i == n-1 or j == 0 or j == n-1)
        bfs(i, j);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (vis[i][j])
        cout << 0 << ' ';
      else
        cout << (map[i][j] == 1 ? 1 : 2) << ' ';
    cout << endl;
  }
  return 0;
}
