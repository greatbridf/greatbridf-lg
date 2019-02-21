/*
 * Hermite 多项式
 */

#include <iostream>

using namespace std;

int hermit(int n, int x);

int main() {
  int n, x;
  cin >> n >> x;
  cout << hermit(n, x);
  return 0;
}

int hermit(int n, int x) {
  if (n == 0) return 1;
  if (n == 1) return 2*x;
  return 2 * x * hermit(n-1, x) - 2 * (n-1) * hermit(n-2, x);
}

