/*
 * 连分数
 */

#include <iostream>

using namespace std;

double frac(double x, double n);

int main() {
  double x, n;
  cin >> x >> n;
  cout << frac(x, n);
  return 0;
}

double frac(double x, double n) {
  return n == 1 ? x/(x+1) : x/(n+frac(x, n-1));
}
