#include<iostream>
using namespace std;
int a[30005];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        a[x]=1;
    }
    for(int i=1; i<=30000; i++) {
        if(a[i]==1)k--;
        if(k==0) {
            cout<<i;
            return 0;
        }
    }
    cout<<"NO RESULT";
    return 0;
}
