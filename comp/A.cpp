#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

int buf[4];

void toBits(int n) {
  memset(buf, 0x00, sizeof(buf));
  for (int i = 0; i < 4; ++i) {
    buf[i] = n % 10;
    n /= 10;
  }
}

int toInt() {
  int result = 0;
  for (int i = 0; i < 4; ++i) {
    result *= 10;
    result += buf[i];
  }
  return result;
}

bool SM(int a, int b) { return a < b; }
bool BG(int a, int b) { return a > b; }

int smallize(int n) {
  toBits(n);
  sort(buf, buf+4, SM);
  return toInt();
}

int bigize(int n) {
  toBits(n);
  sort(buf, buf+4, BG);
  return toInt();
}

int reverse(int n) {
  toBits(n);
  swap(buf[0], buf[3]);
  swap(buf[1], buf[2]);
  return toInt();
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int result = 0, num = 0;
    cin >> num;
    while (++result) {
      int tmp = bigize(num) - smallize(num);
      if (num == tmp) {
        break;
      }
      num = tmp;
    }
    cout << result << endl;
  }
  return 0;
}
