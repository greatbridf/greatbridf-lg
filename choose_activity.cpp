#include <iostream>
#include <algorithm>

using namespace std;

typedef struct activity {
  int start, end;
  bool valid = true;
} activity;

int main() {
  int n = 0;
  cin >> n;
  activity* arr = new activity[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].start >> arr[i].end;
  }
  sort(arr, arr+n, [](activity a, activity b) {
    return a.start < b.start;
  });
  int end_time = 0;
  for (int i = 0; i < n-1; ++i) {
    if (arr[i].start == arr[i+1].start) {
      // TODO ?
    }
  }
  return 0;
}
