#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int palindrome(int n) {
  int r = 0;
  while (n != 0) {
    r *= 10;
    r += (n % 10);
    n /= 10;
  }
  return r;
}

bool isPrime(int n) {
  if (n < 2) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i)
    if (n % i == 0) return false;
  return true;
}

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; ++i) {
    if (i > 10000000) break;          // 沙雕判断
    if (palindrome(i) == i && isPrime(i))
      printf("%d\n", i);
  }
  return 0;
}
