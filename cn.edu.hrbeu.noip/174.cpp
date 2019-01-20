#include <iostream>
#include <algorithm>

using namespace std;

// Low efficiency
// TODO: Optimize algorithm

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  int max, min;
  cin >> arr[0];
  max = arr[0], min = arr[0];
  for (int i = 1; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
  }
  int* s = new int[max - min + 1];
  int result = 0;
  for (int i = 0; i < n; ++i){
    if (s[arr[i]-min] != 1) {
      ++result;
      s[arr[i]-min] = 1;
    }
  }
  cout << result << endl;
  for (int i = 0; i < max - min + 1; ++i) {
    if (s[i] == 1) cout << i+min << " ";
  }
  delete [] s;
  delete [] arr;
  return 0;
}
