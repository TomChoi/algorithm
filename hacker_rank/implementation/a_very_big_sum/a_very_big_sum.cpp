#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll> ar) {
    int n=ar.size();
    ll ans=0;
    for(int i=0; i<n; ++i) {
        ans+=ar[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<ll> a;

    cin>>n;
    for(int i=0; i<n; ++i) {
        ll e;
        cin>>e;
        a.push_back(e);
    }

    ll ans = solve(a);
    cout<<ans<<"\n";

    return 0;
}
