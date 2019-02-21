/*
 * 机器翻译
 */

#include <iostream>
#include <memory.h>

using namespace std;

int mem[100];
int memSize = 0, curr = 0;

int lookup(int);

int main() {
  memset(mem, -1, sizeof(mem));
  int n;
  cin >> memSize >> n;
  int result = 0;
  int tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    result += lookup(tmp);
  }
  cout << result;
  return 0;
}

int lookup(int n) {
  for (int i = 0; i < memSize && mem[i] != -1; ++i) {
    if (mem[i] == n) return 0;
  }
  mem[curr] = n;
  ++curr;
  if (curr == memSize) curr = 0;
  return 1;
}

