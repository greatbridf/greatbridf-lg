#include <iostream>
#include <stack>

using namespace std;

bool flag = true;

int main() {
  char str[301] = { 0x00 };
  cin >> str;
  stack<char> sta;
  char* c = str;
  while (*c != '@') {
    if (*c == '(' || *c == '[' || *c == '{') {
      if (*c == '(') {
        sta.push(')');
      }
      if (*c == '[') {
        sta.push(']');
      }
      if (*c == '{') {
        sta.push('}');
      }
    } else {
      if (*c == ')' || *c == ']' || *c == '}') {
        if (*c == sta.top()) {
          sta.pop();
        } else {
          flag = false;
          break;
        }
      }
    }
    ++c;
  }
  if (!sta.empty()) {
    flag = false;
  }
  if (flag) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
