/*
 * 确定进制
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool flag = false;

long long convert(long long num, int n);

int main() {
  long long p, q, r;
  cin >> p >> q >> r;
  for (int i = 2; i <= 16; ++i) {
    if (convert(p, i) * convert(q, i) == convert(r, i) && flag) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}

long long convert(long long num, int n) {
  int a = 0, res = 0;
  while (num != 0) {
    int tmp = num % 10;
    if (tmp >= n) {
      flag = false;
      return -1;
    }
    res += pow(n, a) * tmp;
    num /= 10;
    ++a;
  }
  flag = true;
  return res;
}

