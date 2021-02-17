#include <bits/stdc++.h>
using namespace std;

long solve(int n, vector<long> c) {
    long ans=0;
    if (n<0) return 0;
    else if (n == 0) return 1;

    if (c.size() <= 0 && n > 0) 
        return 0;

    vector<long> v = c;
    int e = v[0];
    v.erase(v.begin());
    return solve(n, v) + solve(n-e, c);
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
