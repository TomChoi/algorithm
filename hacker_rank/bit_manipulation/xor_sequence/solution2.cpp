#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll xorSum(ll x) {
    ll ans=0;
    switch(x%8) {
        case 0: 
        case 1: ans=x;
        break;
        case 2:
        case 3: ans=2;
        break;
        case 4:
        case 5: ans=x+2;
        break;
        case 6:
        case 7: ans=0;
        break;
    }
    return ans;
}

ll solve(ll l, ll r) {
    return xorSum(l-1) ^ xorSum(r);    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<ll>> ar(n);

    for(int i=0; i<n; ++i){
        ar[i].resize(2);
        for(int j=0; j<2; ++j)
            cin>>ar[i][j];
    }

    for(int i=0; i<n; ++i) {
        ll ans = solve(ar[i][0], ar[i][1]);
        cout<<ans<<"\n";
    }

    return 0;
}
