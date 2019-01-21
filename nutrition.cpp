#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef struct Food {
  int fat;
  int k;
} Food;

bool cmp(Food a, Food b) {
  return a.fat > b.fat;
}

int main() {
  int n, max, k;
  cin >> n >> max >> k;
  int* ks = new int[k];
  for (int i = 0; i < k; ++i) scanf("%d", ks+i);
  Food* foods = new Food[n];
  memset(foods, 0x00, sizeof(Food)*n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &foods[i].fat, &foods[i].k);
  sort(foods, foods+n, cmp);
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (max <= 0) break;
    if (ks[foods[i].k-1] > 0) {
      result += foods[i].fat;
      --ks[foods[i].k-1];
      --max;
    }
  }
  cout << result;
  delete [] foods;
  delete [] ks;
  return 0;
}
