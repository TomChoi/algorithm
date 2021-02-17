#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll x) {
    ll ans = 0;
    int idx = 64-__builtin_clzll(x);
    for(int i=0; i<idx; ++i) {
        if((x&(1L<<i))==0) {
            ans += pow(2,i);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll q, x;
    cin>>q;
   
    for(ll i=0; i<q; ++i) {
        cin>>x;
        cout<<solve(x)<<"\n";
    }

    return 0;
}
