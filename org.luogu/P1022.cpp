#include <iostream>
#include <cstdio>

int left, right;

int main() {
  char c = 0x00, a = 0x00;
  int tmp = 0;
  bool isMinus = false;
  while ((c = getchar()) != EOF) {
    if (c == '=') {
      if (isMinus) {
        right += tmp;
      } else {
        right -= tmp;
      }
      isMinus = false;
      tmp = 0;
      break;
    }
    if (c >= 'a' and c <= 'z') {
      a = c;
      if (tmp == 0)
        tmp = 1;
      if (isMinus) {
        left -= tmp;
      } else {
        left += tmp;
      }
      isMinus = false;
      tmp = 0;
    }
    if (c >= '0' and c <= '9') {
      tmp *= 10;
      tmp += (c-'0');
    }
    if (c == '+') {
      if (isMinus) {
        right += tmp;
      } else {
        right -= tmp;
      }
      isMinus = false;
      tmp = 0;
    }
    if (c == '-') {
      if (isMinus) {
        right += tmp;
      } else {
        right -= tmp;
      }
      isMinus = true;
      tmp = 0;
    }
  }
  while ((c = getchar()) != EOF) {
    if (c >= 'a' and c <= 'z') {
      a = c;
      if (tmp == 0)
        tmp = 1;
      if (isMinus) {
        left += tmp;
      } else {
        left -= tmp;
      }
      isMinus = false;
      tmp = 0;
    }
    if (c >= '0' and c <= '9') {
      tmp *= 10;
      tmp += (c-'0');
    }
    if (c == '+') {
      if (isMinus) {
        right -= tmp;
      } else {
        right += tmp;
      }
      isMinus = false;
      tmp = 0;
    }
    if (c == '-') {
      if (isMinus) {
        right -= tmp;
      } else {
        right += tmp;
      }
      isMinus = true;
      tmp = 0;
    }
  }
  if (isMinus) {
    right -= tmp;
  } else {
    right += tmp;
  }
  std::cout << a << '=';
  printf("%.3f", 1.0*right/left == -0.0f ? 0.0 : 1.0*right/left);
  return 0;
}
