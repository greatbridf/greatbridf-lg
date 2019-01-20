// 按开始时间将每个事件排序
// 比较相同开始时间事件的结束时间
// 取该事件的结束时间为i
// 遍历数组，寻找开始时间>i的事件，重复上述操作

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
