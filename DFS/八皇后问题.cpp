#include <iostream>

using namespace std;

int nBSize = 8;

bool col[8];
bool pos[15];
bool neg[15];

int count = 0;

void dfs(int line) {
    if (line == nBSize) {
        ++count;
        return;
    }
    for (int j = 0; j < nBSize; ++j) {
        if (!col[j] && !pos[line+j] && !neg[line-j+nBSize-1]) {
            col[j] = true;
            pos[line+j] = true;
            neg[line-j+nBSize-1] = true;
            dfs(line+1);
            col[j] = false;
            pos[line+j] = false;
            neg[line-j+nBSize-1] = false;
        }
    }
}

int main() {
    dfs(0);
    cout << count;
    return 0;
}

