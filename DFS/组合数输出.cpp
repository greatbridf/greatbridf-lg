#include <iostream>

int max, count;

int ans[9];

void dfs(int n, int num) {
    if (num == count) {
        for (int i = 0; i < count; ++i) {
            std::cout << ans[i];
        }
        std::cout << std::endl;
        return;
    }
    for (int i = max; i >= 1; --i) {
        if (num == 0 || ans[num-1] > i) {
            ans[num] = i;
            dfs(n+1, num+1);
        }
    }
}

int main() {
    while (std::cin >> max >> count) {
        dfs(1, 0);
    }
    return 0;
}

