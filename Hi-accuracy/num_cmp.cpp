#include <iostream>
#include <string>

using namespace std;

// 1: a > b; -1: a < b; 0: 1 a == b
int cmp(int* a, int* b) {
  if (a[0] > b[0]) return 1;
  if (a[0] < b[0]) return -1;
  for (int i = 1; i <= a[0]; ++i) {
    if (a[i] > b[i]) return 1;
    if (a[i] < b[i]) return -1;
  }
  return 0;
}

void output(int* num) {
  for (int i = 1; i <= num[0]; ++i) {
    cout << num[i];
  }
}

int main() {
  int a[100] = {};
  int b[100] = {};
  int c[100] = {};
  string tmp;
  cin >> tmp;
  a[0] = tmp.length();
  for (int i = 0; i < a[0]; ++i)
    a[i+1] = tmp[i]-'0';
  cin >> tmp;
  b[0] = tmp.length();
  for (int i = 0; i < b[0]; ++i)
    b[i+1] = tmp[i]-'0';
  cin >> tmp;
  c[0] = tmp.length();
  for (int i = 0; i < c[0]; ++i)
    c[i+1] = tmp[i]-'0';
  switch(cmp(a, b)) {
    case 0:
      if (cmp(a, c) > 0) output(a);
      else output(c);
      break;
    case 1:
      if (cmp(a, c) > 0) output(a);
      else output(c);
      break;
    case -1:
      if (cmp(b, c) > 0) output(b);
      else output(c);
      break;
  }
  return 0;
}
