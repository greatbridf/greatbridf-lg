/*
 * 斐波那契数列
 */

#include <iostream>

using namespace std;

int fibo(int n);

int main() {
  int n;
  cin >> n;
  cout << fibo(n);
  return 0;
}

int fibo(int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  return fibo(n-1)+fibo(n-2);
}

