#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<int, int> maps;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++maps[tmp];
    }
    for (auto it = maps.rbegin(); it != maps.rend(); ++it) {
        cout << it->first << ":" << it->second << endl;
    }
    cout << maps.size();
    return 0;
}
