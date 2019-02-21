/*
 * 区间内的真素数
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);
int palindrome(int n);

int main() {
  int m, n;
  cin >> m >> n;
  bool flag = false;
  for (int i = m; i <= n; ++i) {
    if (isPrime(i) && isPrime(palindrome(i))) {
      if (flag) cout << ',';
      else flag = true;
      cout << i;
    }
  }
  if (!flag)
    cout << "No";
  return 0;
}

bool isPrime(int n) {
  if (n == 0 || n == 1) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int palindrome(int n) {
  int r = 0;
  while (n != 0) {
    r *= 10;
    r += (n % 10);
    n /= 10;
  }
  return r;
}

