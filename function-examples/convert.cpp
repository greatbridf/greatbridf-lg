#include <iostream>

using namespace std;

char cs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void turnData(int a, int n) {
  char result[16] = {-1};
  if (a < 0) {
    cout << '-';
    a -= 2*a;
  }
  for (int i = 0; i < 16; ++i) {
    result[i] = cs[a%n];
    a /= n;
    if (a == 0) break;
  }
  for (int i = 15; i >= 0; --i)
    if (result[i] != -1) cout << result[i];
  cout << endl;
}

int main() {
  int a, n;
  cin >> a >> n;
  turnData(a, n);
  return 0;
}
