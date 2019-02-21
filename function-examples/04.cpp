/*
 * 统计单词数
 */

#include <iostream>
#include <string>

using namespace std;

void strToLower(string &str);

int main() {
  string word, line;
  getline(cin, word);
  getline(cin, line);
  strToLower(word);
  strToLower(line);
  int len = word.size(), linelen = line.size();

  int count = 0, first = -1;
  string::size_type pos = 0;
  while ((pos = line.find(word, pos)) != string::npos) {
    if ( (pos == 0 || line[pos-1] == ' ') && (pos+len == linelen || line[pos+len] == ' ') ) {
      if (first == -1) first = pos;
      ++count;
      ++pos;
    }
    ++pos;
    continue;
  }
  if (first == -1) cout << -1;
  else cout << count << " " << first;
  return 0;
}

void strToLower(string &str) {
  int size = str.size();
  for (int i = 0; i < size; ++i) {
    str[i] = tolower(str[i]);
  }
}

