/*
 * 最大质因子序列
 */

#include <iostream>
#include <cmath>

using namespace std;

bool primeList[5001];

void primeInit();
bool isPrime(int n);
int gpf(int n);

int main() {
  int m, n;
  cin >> m >> n;
  primeInit();
  for (int i = m; i <= n; ++i) {
    if (isPrime(i))
      cout << i;
    else
      cout << gpf(i);

    if (i != n)
      cout << ',';
  }
  return 0;
}

int gpf(int n) {
  int res = 1;
  for (int i = 2; i < n; ++i) {
    if (primeList[i] && n % i == 0)
      res = i;
  }
  return res;
}

void primeInit() {
  for (int i = 1; i <= 5000; ++i) {
    if (isPrime(i))
      primeList[i] = true;
  }
}

bool isPrime(int n) {
  if (n == 0 || n == 1) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

