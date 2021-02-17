#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n) {
    return pow(2,64-__builtin_clzll(n)-__builtin_popcountll(n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    
    ll ans=solve(n);
    cout<<ans<<"\n";

    return 0;
}

    
