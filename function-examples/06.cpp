/*
 * Vigenere密码
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void strToLower(string& str);
char decrypt(char src, char key);

int main() {
  string key, str;
  cin >> key >> str;
  strToLower(key);
  int keyindex = 0, strsize = str.size(), keysize = key.size();
  for (int i = 0; i < strsize; ++i) {
    if (keyindex == keysize) keyindex = 0;
    cout << decrypt(str[i], key[keyindex++]);
  }
  return 0;
}

char decrypt(char n, char key) {
  char tmp = n - key + 'a';
  if (n < 'Z'+1 && tmp < 'A') return tmp + 26;
  if (n > 'a'-1 && tmp < 'a') return tmp + 26;
  return tmp;
}

void strToLower(string& str) {
  int len = str.size();
  for (int i = 0; i < len; ++i)
    str[i] = tolower(str[i]);
}

