#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c;

bool flag = false;

bool visited[10] = {false};

bool judge(int n) {
  bool tmp[10] = {false};
  if (n % a != 0) return false;
  int r = n/a;
  r *= (a+1000*b+1000000*c);
  while (r != 0) {
    if (r%10 == 0 or tmp[r%10] == true)
      return false;
    tmp[r%10] = true;
    r /= 10;
  }
  return true;
}

void dfs(int n) {
  if (n > 100) {
    if (n/a*c < 1000 and judge(n)) {
      cout << n << ' ' << n/a*b << ' ' << n/a*c << endl;
      flag = true;
    }
    return;
  }
  for (int i = 1; i < 10; ++i) {
    if (not visited[i]) {
      visited[i] = true;
      dfs(n*10+i);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> a >> b >> c;
  dfs(0);
  if (not flag)
    cout << "No!!!";
  return 0;
}
