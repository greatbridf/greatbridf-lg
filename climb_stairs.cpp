#include <iostream>

using namespace std;

int up(int n) {
  if (n <= 2) return n;
  return up(n-1) + up(n-2);
}

int main() {
  int n;
  while (cin >> n) {
    cout << up(n) << endl;
  }
  return 0;
}

