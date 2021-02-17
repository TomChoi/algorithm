#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr) {
    float pc=0, nc=0, zc=0;
    int n=arr.size();
    for(int i=0; i<n; ++i) {
        if (arr[i] > 0) {
            pc++;
        } else if (arr[i] < 0) {
            nc++;
        } else {
            zc++;
        }
    }
    cout<<round(pc/n*1000000)/1000000<<"\n";
    cout<<round(nc/n*1000000)/1000000<<"\n";
    cout<<round(zc/n*1000000)/1000000<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> ar(n);

    for(int i=0; i<n; ++i) {
        int e;
        cin>>e;
        ar[i]=e;
    }

    solve(ar);

    return 0;
}
