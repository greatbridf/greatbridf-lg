#include <iostream>

using namespace std;

int frac(int);

int main() {
  int n = 0;
  while (cin >> n) {
    cout << frac(n) << endl;
  }
  return 0;
}

int frac(int n) {
  if (n == 0 || n == 1) return 1;
  return n * frac(n-1);
}
