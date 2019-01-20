#include <iostream>

using namespace std;

int main() {
  int arr[100] = {};
  int n = 0;
  while (true) {
    cin >> arr[n];
    if (arr[n] == 0) break;
    ++n;
  }
  --n;
  for (int i = n; i >= 0; --i) {
    cout << arr[i] << " ";
  }
  return 0;
}
