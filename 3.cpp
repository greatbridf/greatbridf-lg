#include <iostream>
#include <string>

using namespace std;

int ans[1000] = {};

void multiply(int* a, int* b) {
  ans[0] = a[0] + b[0];
  for (int i = 1; i <= a[0]; ++i) {
    for (int j = 1; j <= b[0]; ++j) {
      ans[1+i-1+j-1] += a[i]*b[j];
      ans[1+i-1+j-1+1] += ans[1+i-1+j-1]/10;
      ans[1+i-1+j-1] %= 10;
    }
  }
  while (ans[ans[0]] == 0) --ans[0];
  return;
}

void output(int* n) {
  for (int i = n[0]; i >= 1; --i)
    cout << n[i];
  return;
}

void input(int* a, int src) {
  int len = 0;
  while (src) {
    a[len+1] = src%10;
    src /= 10;
    ++len;
  }
  a[0] = len;
  return;
}

int main() {
  int n;
  cin >> n;
  input(ans, 1);
  for (int i = 2; i <= n; ++i) {
    int tmp[10] = {};
    input(tmp, i);
    multiply(ans, tmp);
  }
  output(ans);
  cout << endl;
  return 0;
}

