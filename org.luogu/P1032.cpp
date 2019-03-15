#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int result, n;
string src, dest, rules[6][2];

typedef struct {
  string str;
  int times;
} Node;

void bfs() {
  queue<Node> Q;
  map<string, bool> M;
  Node fi = {src, 0};
  Q.push(fi);

  while (not Q.empty()) {
    Node tmp = Q.front();
    Q.pop();

    if (tmp.times == 10)
      break;

    if (M.count(tmp.str))
      continue;
    M[tmp.str] = true;

    if (tmp.str == dest) {
      result = tmp.times;
      break;
    }

    for (int i = 0; i < n; ++i) {
      size_t pos = 0;
      while ((pos = tmp.str.find(rules[i][0], pos)) != string::npos) {
        string t = tmp.str;
        t.replace(pos, rules[i][0].length(), rules[i][1]);
        Node a = {t, tmp.times+1};
        Q.push(a);
        pos += rules[i][1].length();
      }
    }
  }
}

int main() {
  cin >> src >> dest;
  string tmp;
  while (n < 6 and cin >> tmp) {
    string tmp_dest;
    cin >> tmp_dest;
    rules[n][0] = tmp;
    rules[n][1] = tmp_dest;
    ++n;
  }

  bfs();

  if (result != 0)
    cout << result;
  else
    cout << "NO ANSWER!";
  return 0;
}

