/*
 * 我家的门牌号
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double myID(int sum, int n);

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= 50000; ++i) {
    sum += i;
    double mine = myID(sum, n);
    if (mine > 0 && mine <= i && fmod(mine, 1) == 0) {
      printf("%d %d", (int)mine, i);
      break;
    }
  }
  return 0;
}

double myID(int sum, int n) {
  return 1.0*(sum - n) / 2;
}

