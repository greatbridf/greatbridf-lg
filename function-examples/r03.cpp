/*
 * 倒序数
 */

#include <iostream>

using namespace std;

void reverse(int n);

int main() {
  int n;
  cin >> n;
  reverse(n);
  return 0;
}

void reverse(int n) {
  cout << n % 10;
  if (n > 10) reverse(n/10);
}

