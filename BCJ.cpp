#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct Road {
    int begin;
    int end;
    int duration;
} Road;

int villages[1000];
int nRoad = 0;

bool cmp(Road a, Road b) {
    return (a.duration < b.duration);
}

int find(int a) {
    return villages[a] == a ? a : find(villages[a]);
}

void awase(int a, int b) {
	if (villages[a] == villages[b]) return;
    for (int i = 0; i < nRoad; ++i)
        if (villages[i] == villages[a])
            villages[i] = villages[b];
    return;
}

bool fin(int nVill) {
    int n = villages[0];
    for (int i = 1; i < nVill; ++i) {
        if (villages[i] != n)
            return false;
    }
    return true;
}

int main() {
    int nVill;
    cin >> nVill >> nRoad;
    for (int i = 0; i < nVill; ++i) villages[i] = i;
    Road* rs = new Road[nRoad];
    for (int i = 0; i < nRoad; ++i) {
        int a, b;
        scanf("%d%d%d", &a, &b, &rs[i].duration);
        if (a > b) rs[i].begin = b, rs[i].end = a;
        else rs[i].begin = a, rs[i].end = b;
    }
    sort(rs, rs+nRoad, cmp);
    int result = 0;
    for (int i = 0; i < nRoad; ++i) {
        if (fin(nVill)) break;
        awase(rs[i].begin, rs[i].end);
        result += rs[i].duration;
    }
    if (fin(nVill)) cout << result;
    else cout << -1;
    delete [] rs;
    return 0;
}
