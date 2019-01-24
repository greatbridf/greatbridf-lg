#include <iostream>
#include <cmath>

int max;

bool vis[20] = {true, false};
int ans[20] = {1, 0};

bool is_prime(int a) {
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a%i==0) return false;
    }
    return true;
}

void dfs(int n) {
    if (n == max+1 && is_prime(ans[0] + ans[max-1])) {
        for (int i = 0; i < max; ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 2; i <= max; ++i) {
        if (!vis[i] && is_prime(ans[n-2] + i)) {
            vis[i] = true;
            ans[n-1] = i;
            dfs(n+1);
            vis[i] = false;
        }
    }
}

int main() {
    while (std::cin >> max) {
        dfs(2);
    }
    return 0;
}

