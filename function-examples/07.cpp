/*
 * 素数对
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int);

int main() {
  int n;
  cin >> n;
  bool exist = false;
  for (int i = 3; i+2 <= n; ++i) {
    if (isPrime(i) && isPrime(i+2)) {
      cout << i << " " << i + 2 << endl;
      if (!exist) exist = true;
    }
  }
  if (!exist) cout << "empty";
  return 0;
}

bool isPrime(int n) {
  if (n == 1) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

