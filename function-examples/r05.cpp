/*
 * 逆序输出字符串
 */

#include <iostream>
#include <string>

using namespace std;

void output(string str, int i);

int main() {
  string a;
  cin >> a;
  output(a, 0);
  return 0;
}

void output(string str, int i) {
  if (str[i] != '!') output(str, i+1);
  cout << str[i];
}

