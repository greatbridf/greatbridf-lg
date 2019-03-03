#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct Apple {
  int height;
  int power;
} Apple;

bool cmp(Apple a, Apple b) {
  return a.power < b.power;
}

int main() {
  int n, power, chair, height;
  cin >> n >> power >> chair >> height;
  height += chair;
  Apple* arr = new Apple[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &arr[i].height, &arr[i].power);
  }
  sort(arr, arr+n, cmp);
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (power < 0) break;
    if (height >= arr[i].height && power >= arr[i].power) {
      ++result;
      power -= arr[i].power;
    }
  }
  cout << result;
  return 0;
}
