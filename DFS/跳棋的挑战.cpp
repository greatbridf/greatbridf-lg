#include <iostream>

using namespace std;

bool col[13];
bool pos[25];
bool neg[25];

int nBSize = 0;

int ans[13];
int nCount = 0;

void dfs(int line) {
    if (line == nBSize) {
        if (nCount < 3) {
           for (int i = 0; i < nBSize; ++i) {
              cout << ans[i]+1 << " ";
           } 
           cout << endl;
        }
        ++nCount;
        return;
    }
    for (int nCol = 0; nCol < nBSize; ++nCol) {
        if (!col[nCol] && !pos[line+nCol] && !neg[line-nCol+nBSize-1]) {
            col[nCol] = true;
            pos[line+nCol] = true;
            neg[line-nCol+nBSize-1] = true;
            ans[line] = nCol;
            dfs(line+1);
            col[nCol] = false;
            pos[line+nCol] = false;
            neg[line-nCol+nBSize-1] = false;
        }
    }
}

int main() {
    while (cin >> nBSize) {
        nCount = 0;
        dfs(0);
        cout << nCount << endl;
    }
    return 0;
}

