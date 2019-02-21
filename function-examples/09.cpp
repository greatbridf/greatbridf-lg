/*
 * 质数的和与积
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main() {
  int n;
  cin >> n;
  int result = 0, tmp = 0;
  for (int i = 1; i <= n/2; ++i) {
    if (isPrime(i) && isPrime(n-i)) {
      tmp = i * (n-i);
      if (tmp > result) result = tmp;
    }
  }
  cout << result;
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

