#include <iostream>

using namespace std;

int main() {
  int arr[10] = {};
  for (int i = 0; i < 10; ++i)
    scanf("%d", arr+i);
  int height;
  scanf("%d", &height);
  height += 30;
  int result = 0;
  for (int i = 0; i < 10; ++i) {
    if (arr[i] <= height) ++result;
  }
  printf("%d", result);
  return 0;
}
