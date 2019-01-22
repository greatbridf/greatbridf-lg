// Luogu P1551
// Requires optimize
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int set[500000];
int person;

bool find(int a) {
   /*
    *  Improved find
    *  Point target node directly
    *  to root node
    */
    return set[a] == a ? a : set[a] = find(set[a]);
}

void awase(int a, int b) {
    if (set[a] == set[b]) return;
    for (int i = 0; i < person; ++i) {
        if (set[i] == set[a]) {
            set[i] = set[b];
        }
    }
}

int main() {
    int relations, questions;
    cin >> person >> relations >> questions;
    for (int i = 0; i < person; ++i) set[i] = i;
    int a, b;
    for (int i = 0; i < relations; ++i) {
        scanf("%d%d", &a, &b);
        awase(a, b);
    }
    for (int i = 0; i < questions; ++i) {
        scanf("%d%d", &a, &b);
        if (find(a) == find(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
