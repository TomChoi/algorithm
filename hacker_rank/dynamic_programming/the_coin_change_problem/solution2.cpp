#include <bits/stdc++.h>
using namespace std;

long solve(int n, vector<long> c) {
    vector<long> v(n+1, 0);
    v[0]=1;

    for(int i=0; i<c.size(); ++i) {
        for(int j=c[i]; j<=n; ++j) {
            v[j] += v[j-c[i]];
        }
    }
    return v[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<long> a(m);
    for(int i=0; i<m; ++i)
        cin>>a[i];

    long ans=solve(n,a);
    cout<<ans<<"\n";

    return 0;
}
