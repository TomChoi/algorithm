#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll l, ll r) {
    ll ans=0,s=0;
    if(l%4 == 0) s=l;
    else if (l%4 == 1) s=1;
    else if (l%4 == 2) s=l+1;
    else s=0;

    ans=s;
    l++; 

    if(l>r) return ans;
    
    while(l%4 != 0 && l<=r) {
        s ^= l++;
        ans ^= s;
    }

    if(l>r) return ans;
    
    ll rs=0;
    if (r%4 != 3) {
        ll nr=r-r%4;

        if(nr%4 == 0) s=nr;
        else if(nr%4 == 1) s=1;
        else if(nr%4 == 2) s=nr+1;
        else s=0;
        nr++;
        rs=s;
        while(nr<=r) {
            s ^= nr++;
            rs ^= s;
        }
        r-=r%4-1;
    }
    ans ^= ((r-l+1)/4)%2 ? 2 : 0;
    ans ^=rs;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<vector<ll>> q(n);
    for(int i=0; i<n; ++i){
        q[i].resize(2);
        for(int j=0; j<2; ++j)
            cin>>q[i][j];
    }
    
    for(int i=0; i<n; ++i){
        ll ans=solve(q[i][0], q[i][1]);
        cout<<ans<<"\n";
    }
    return 0;
}
