#include <iostream>

using namespace std;

int n;

int ans[10001];

void dfs(int cur, int sum) {
    if (sum == n) {
        for (int i = 0; i < cur-2; ++i)
            cout << ans[i] << "+";
        cout << ans[cur-2] << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (sum < n && (cur == 1 || ans[cur-2] <= i)) {
            ans[cur-1] = i;
            dfs(cur+1, sum+i);
        }
    }
}

int main() {
    while (cin >> n) {
        dfs(1, 0);
    }
    return 0;
}

