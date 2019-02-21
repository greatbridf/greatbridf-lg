/*
 * 判决素数个数
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int result = 0;
  for (int i = a; i <= b; ++i) {
    if (isPrime(i)) ++result;
  }
  cout << result;
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

