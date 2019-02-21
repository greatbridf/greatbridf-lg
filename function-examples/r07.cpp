/*
 * 分离第n个数
 */

#include <iostream>

using namespace std;

int sep(int n, int k);

int main() {
  int n, k;
  cin >> n >> k;
  cout << sep(n, k);
  return 0;
}

int sep(int n, int k) {
  if (k == 1) return n % 10;
  return sep(n/10, k-1);
}

