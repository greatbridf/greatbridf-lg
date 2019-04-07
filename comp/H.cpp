#include <iostream>

using namespace std;

int ABS(int n) {
  return n > 0 ? n : 0-n;
}

int dU(int a) {
  return int(1.0*a/2+0.5);
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int result = 1;
  while (b - a != 1 || (b - a == 1 && a % 2 == 0)) {
    a -= dU(a-1);
    b -= dU(b-1);
    ++result;
  }
  cout << result;
  return 0;
}
