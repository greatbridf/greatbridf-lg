// 按结束时间升序排列
// 如下一个活动的开始时间>=现在的结束时间 选择
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

typedef struct ac {
    int begin;
    int end;
} ac;

bool cmp(ac a, ac b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    ac* acs = new ac[n];
    memset(acs, 0x00, sizeof(acs)*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &acs[i].begin, &acs[i].end);
    }
    sort(acs, acs+n, cmp);
    int end_time = acs[0].end;
    int result = 1;
    for (int i = 1; i < n; ++i) {
        if (acs[i].begin >= end_time) {
            end_time = acs[i].end;
            ++result;
        }
    }
    cout << result;
    delete [] acs;
    return 0;
}
