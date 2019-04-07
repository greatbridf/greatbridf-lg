#include <iostream>

using namespace std;

int main() {
  int len, a, b, time, aS = 1, bS = 1;
  cin >> len >> a >> b >> time;
  for (int i = 0; i < time; ++i) {
    if (a == len || a == 0) aS *= -1;
    if (b == len || b == 0) bS *= -1;
    if (a == b) {
      aS *= -1;
      bS *= -1;
    }
    a += aS;
    b += bS;
  }
  cout << a << b;
  return 0;
}
