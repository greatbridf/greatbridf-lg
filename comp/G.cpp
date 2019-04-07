#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, five = 0, ten = 0, tmp = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    if (tmp == 5) {
      ++five;
      continue;
    }
    if (tmp == 10) {
      if (five == 0) {
        cout << i;
        return 0;
      }
      --five;
      ++ten;
      continue;
    }
    if (tmp == 20) {
      if (five-1 < 0 || ten-1 < 0) {
        if (five-3 < 0) {
          cout << i;
          return 0;
        } else {
          five -= 3;
        }
      } else {
        --five;
        --ten;
      }
      continue;
    }
  }
  cout << n;
  return 0;
}
