/*
 * ???
 */

#include <iostream>
#include <cmath>

using namespace std;

double fun(double x, int n);

int main() {
  int n;
  double x;
  cin >> x >> n;
  cout << fun(x, n);
  return 0;
}

double fun(double x, int n) {
  return n == 1 ? sqrt(1+x) : sqrt(n+fun(x, n-1));
}

