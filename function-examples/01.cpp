/*
 * 简单算术表达式求值
 */
#include <iostream>

using namespace std;

int calc(int, int, char);

int main() {
  int a = 0, b = 0;
  char op = 0;
  cin >> a >> op >> b;
  cout << calc(a, b, op) << endl;
  return 0;
}

int calc(int a, int b, char op) {
  switch(op) {
    case '+':
      return a + b;
      break;
    case '-':
      return a - b;
      break;
    case '*':
      return a * b;
      break;
    case '/':
      return a / b;
      break;
    case '%':
      return a % b;
      break;
    default:
      return -1;
      break;
  }
  return -1;
}
