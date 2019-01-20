// Failed tests
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  string target;
  cin >> target;
  transform(target.begin(), target.end(), target.begin(), ::tolower);
  int first = -1, total = 0, i = 0;
  string tmp = "";
  while (cin >> tmp) {
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    if (strcmp(tmp.c_str(), target.c_str()) == 0) {
      if (first == -1) first = i;
      ++total;
    }
    ++i;
  }
  if (first == -1) cout << first;
  else cout << total << " " << first;
  return 0;
}
