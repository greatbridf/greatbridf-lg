#include <iostream>

using namespace std;

bool col[13];
bool pos[25];
bool neg[25];

int nBSize = 0;

void dfs(int line) {
    for (int nCol = 0; nCol < nBSize; ++nCol) {
        if (!col[nCol] && !pos[line+nCol] && !neg[line-nCol+nBSize-1]) {
            col[nCol] = true;
            pos[line+nCol] = true;
            neg[line-nCol+nBSize-1] = true;
            dfs(line+1);
        }
    }
}

int main() {
    while (cin >> nBSize) {
        dfs(0);
    }
    return 0;
}

