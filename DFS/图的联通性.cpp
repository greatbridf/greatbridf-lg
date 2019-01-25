#include <iostream>
#include <memory.h>

using namespace std;

int points, sides;

bool map[1000][1000];
bool com[1000];
int count = 0;

void dfs(int n) {
    com[n] = true;
    ++count;
    if (count == points)
        return;
    for (int i = 0; i < points; ++i) {
        if (!com[i] && map[n][i]) {
            dfs(i);
        }
    }
}

int main() {
    int a, b;
    while (cin >> points >> sides) {
        memset(map, 0x00, sizeof(map));
        memset(com, 0x00, sizeof(com));
        count = 0;
        for (int i = 0; i < sides; ++i) {
            cin >> a >> b;
            map[a-1][b-1] = true;
            map[b-1][a-1] = true;
        }
        dfs(0);
        if (count == points) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
