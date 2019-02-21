/*
 * 进制转换
 */

#include <iostream>

using namespace std;

char nums[] = {'A', 'B', 'C', 'D', 'E', 'F'};

void convert(int n, int m);

int main() {
  int n, m;
  cin >> n >> m;
  convert(n, m);
  return 0;
}

void convert(int n, int m) {
  if (n >= m) convert(n/m, m);
  if ((n%m) >= 10)
    cout << nums[(n%m)-10];
  else
    cout << n%m;
}

