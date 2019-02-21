/*
 * 素数回文数的个数
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);
bool isPalindrome(int n);

int main() {
  int n;
  cin >> n;
  int result = 0;
  for (int i = 11; i <= n; ++i) {
    if (isPrime(i) && isPalindrome(i)) {
      ++result;
    }
  }
  cout << result;
  return 0;
}

bool isPalindrome(int n) {
  int a = n, r = 0;
  while (a != 0) {
    r *= 10;
    r += (a % 10);
    a /= 10;
  }
  return r == n;
}

bool isPrime(int n) {
  if (n == 0 || n == 1) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

