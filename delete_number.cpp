#include <iostream>
#include <string>

using namespace std;

void output(string);

int main() {
  int times;
  string INPUT;
  cin >> INPUT >> times;
  for (int i = 0; i < INPUT.size(); ++i) {
    if (times == 0) {
      output(INPUT);
      return 0;
    }
    if (INPUT[i] > INPUT[i+1]) {
      INPUT.erase(i, 1);
      --times, --i;
    }
  }
  while (times--)
    INPUT.pop_back();
  output(INPUT);
  return 0;
}

void output(string str) {
  bool flag = false;
  for (auto itr = str.begin(); itr != str.end(); ++itr) {
    if (flag) break;
    if (*itr == '0') {
      itr = str.erase(itr);
      --itr;
    } else 
      flag = true;
  }
  cout << str;
}
