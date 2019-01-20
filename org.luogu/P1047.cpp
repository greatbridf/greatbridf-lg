#include <iostream>
#include <memory.h>

using namespace std;

typedef struct Range {
  int startPos;
  int endPos;
} Range;

int main() {
  int len, n;
  cin >> len >> n;
  Range* ranges = new Range[n];
  bool* road = new bool[len+1];
  memset(road, 0x00, sizeof(bool)*(len+1));
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &ranges[i].startPos, &ranges[i].endPos);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = ranges[i].startPos; j <= ranges[i].endPos; ++j) {
      road[j] = true;
    }
  }
  int result = 0;
  for (int i = 0; i < len+1; ++i) {
    if (!road[i]) {
      ++result;
    }
  }
  printf("%d", result);
  return 0;
}
