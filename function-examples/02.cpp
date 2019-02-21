/*
 * 短信计费
 */

#include <iostream>

using namespace std;

int send(int);

int main() {
  double result = 0;
  int n = 0, tmp = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    result += 0.1 * send(tmp);
  }
  printf("%.1f", result);
  return 0;
}

int send(int a) {
  int result = 0;
  do {
    ++result;
    a -= 70;
  } while (a > 0);
  return result;
}

