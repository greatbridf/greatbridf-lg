/*
 * 笨小猴
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int arr[26];

int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) {
    ++arr[str[i]-'a'];
  }
  int max = 0, min = 2147483647;
  for (int i = 0; i < 26; ++i) {
    if (arr[i] == 0) continue;
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
  }
  if (isPrime(max-min)) {
    cout << "Lucky Word" << endl << max-min;
  } else {
    cout << "No Answer" << endl << 0;
  }
  return 0;
}

bool isPrime(int n) {
  if (n == 1 || n == 0) return false;
  int s = sqrt(n);
  for (int i = 2; i <= s; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

