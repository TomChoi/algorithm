#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            cout<<" ";
        }

        for(int j=0; j<i+1; ++j) {
            cout<<"#";
        }
        cout<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    solve(n);

    return 0;
}
