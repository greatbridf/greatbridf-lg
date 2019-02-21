/*
 * 二进制分类
 */

#include <iostream>
#include <memory.h>

using namespace std;

char res[10];

void toBinary(int n);
bool isAType(int n);

int main() {
  int a = 0, b = 0;
  for (int i = 1; i <= 1000; ++i) {
    if (isAType(i)) ++a;
    else ++b;
  }
  cout << a << " " << b;
  return 0;
}

void toBinary(int n) {
  memset(res, -1, sizeof(res));
  int i = 0;
  while (n != 0) {
    res[i] = n % 2;   // 逆序存储
    n /= 2;
    ++i;
  }
}

bool isAType(int n) {
  int one = 0, zero = 0;
  toBinary(n);
  for (int i = 0; i < 10 && res[i] != -1; ++i) {
    if (res[i])
      ++one;
    else
      ++zero;
  }
  return one > zero;
}

