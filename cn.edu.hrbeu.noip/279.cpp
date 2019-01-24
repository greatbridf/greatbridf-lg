#include <iostream>

using namespace std;

bool visited[100000] = {false};
int result[100000];

int m;

int sum = 0;

void split(int n) {
  if (n == m && sum == m) {
    cout << result[0];
    for (int i = 1; i < m; ++i)
      cout << "+" << result[i];
    cout << endl;
    sum = 0;
    return;
  } else {
    for (int i = 1; i <= m; ++i) {
      if (!visited[i-1]) {
        visited[i-1] = true;
        result[n-1] = i;
        sum += i;
        split(n+1);
        visited[i-1] = false;
      }
    }
  }
}

int main() {
  cin >> m;
  split(1);
  return 0;
}
