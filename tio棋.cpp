#include <iostream>

bool col[13];
bool pos[25];
bool neg[25];
int ans[13];

int size = 0;
int result_count = 0;

void dfs(int li) {
  if (li == size) {
    if (result_count < 3) {
      for (int i = 0; i < size; ++i) {
          std::cout << ans[i]+1 << " ";
      }
      std::cout << std::endl;
    }
    ++result_count;
  }
  for (int j = 0; j < size; ++j) {
    if (!col[j] && !pos[li+j] && !neg[li-j+size-1]) {
      col[j] = true;
      pos[li+j] = true;
      neg[li-j+size-1] = true;
      ans[li] = j;
      dfs(li+1);
      col[j] = false;
      pos[li+j] = false;
      neg[li-j+size-1] = false;
    }
  }
}

int main() {
  while (std::cin >> size) {
    dfs(0);
    std::cout << result_count << std::endl;
    result_count = 0;
  }
  return 0;
}
