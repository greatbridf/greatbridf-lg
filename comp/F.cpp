#include <iostream>

using namespace std;

int main() {
  int n, k,bottle = 0, result = 0, borrow = 0;
  cin >> n >> k;
  while (true) {
    result += n;
    bottle += n%k;
    n /= k;
    n += bottle / k;
    bottle %= k;
    if (n == 0) {
      if (bottle != 0 && k - bottle == 1) {
        ++result;
      }
      break;
    }
  }
  cout << result;
  return 0;
}
