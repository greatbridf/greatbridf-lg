/*
 * 1 + 2 + ...
 */

#include <iostream>

using namespace std;

int sum(int n);

int main() {
  int n;
  cin >> n;
  cout << sum(n);
  return 0;
}

int sum(int n) {
  return n == 1 ? n : n+sum(n-1);
}

