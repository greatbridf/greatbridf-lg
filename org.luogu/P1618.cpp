#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c;

bool flag = false;

bool visited[10] = {false};

int arr[9];

void dfs(int n) {
  if (n == 9) {
    if ((100*arr[0]+10*arr[1]+arr[2])*a == (100*arr[3]+10*arr[4]+arr[5])*b and (100*arr[0]+10*arr[1]+arr[2])*a == (100*arr[6]+10*arr[7]+arr[8])*c) {
      cout << arr[0] << arr[1] << arr[2] << ' ' << arr[3] << arr[4] << arr[5] << ' ' << arr[6] << arr[7] << arr[8] << endl;
      flag = true;
    }
    return;
  }
  for (int i = 1; i < 10; ++i) {
    if (not visited[i]) {
      visited[i] = true;
      arr[n] = i;
      dfs(n+1);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> a >> b >> c;
  int tmp = a*b*c;
  a = tmp / a;
  b = tmp / b;
  c = tmp / c;
  dfs(0);
  if (not flag)
    cout << "No!!!";
  return 0;
}
