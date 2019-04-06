#include <iostream>

using namespace std;

bool arr[1000];
int results[1000];

int main() {
  int n, tmp, result;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    arr[tmp-1] = true;
  }
  int index = 0;
  for (int i = 0; i < 1000; ++i) {
    if (arr[i]) {
      results[index++] = i+1;
      ++result;
    }
  }
  cout << result << endl;
  for (int i = 0; i < index; ++i) {
    cout << results[i] << ' ';
  }
  return 0;
}

