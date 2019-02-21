/*
 * 单词替换
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  string line, a, b;
  getline(cin, line);
  line += ' ';
  cin >> a >> b;
  string tmp = "";
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] != ' ') {
      tmp += line[i];
    } else {
      if (tmp.compare(a) == 0)
        cout << b << " ";
      else
        cout << tmp << " ";
      tmp = "";
    }
  }
  return 0;
}

