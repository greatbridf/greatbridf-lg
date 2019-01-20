#include <iostream>

using namespace std;

int main() {
  char isbn[14] = "";
  scanf("%s", isbn);
  int tmp = 0, num = 0;
  for (int i = 0; i < 11; ++i) {
    if (i == 1 || i == 5) continue;
    tmp += (isbn[i] - '0')*(num+1);
    ++num;
  }
  if (isbn[12]-'0' == tmp%11 || (tmp%11 == 10 && isbn[12] == 'X')) cout << "Right";
  else {
    if (tmp%11 == 10) isbn[12] = 'X';
    else isbn[12] = tmp%11 + '0';
    cout << isbn;
  }
  return 0;
}
