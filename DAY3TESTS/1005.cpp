#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    char num[11];
    int del;
    scanf("%s %d", num, &del);
    for (char* i = num; *i != 0; ) {
        if (*i > *(i+1) && del != 0) {
            for (char* j = i; *j != 0; ++j) {
                *j = *(j+1);
            }
            i = num;
            --del;
        } else ++i;
    }
    cout << num;
    return 0;
}
