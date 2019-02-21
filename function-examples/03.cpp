/*
 * 甲流病人初筛
 */

#include <iostream>

using namespace std;

bool ill(float, int);

int main() {
  int n = 0, result = 0;
  cin >> n;
  char name[9] = {};
  float temp = 0.0;
  int cough = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s%f%d", name, &temp, &cough);
    if (ill(temp, cough)) {
      cout << name << endl;
      ++result;
    }
  }
  cout << result;
  return 0;
}

bool ill(float temp, int cough) {
  if (cough != 1) return false;
  if (temp >= 37.5) return true;
  return false;
}

