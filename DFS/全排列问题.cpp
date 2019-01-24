#include <iostream>

bool vis[9] = {};
int result[9] = {};

int max;

void dfs(int n) {
    if (n == max+1) {
        for (int i = 0; i < max; ++i) {
            std::cout << result[i];
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= max; ++i) {
        if (!vis[i]) {
            result[n-1] = i;
            vis[i] = true;
            dfs(n+1);
            vis[i] = false;
        }
    }
}

int main() {
    while (std::cin >> max) {
        dfs(1);
    }
    return 0;
}

