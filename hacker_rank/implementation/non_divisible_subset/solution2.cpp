#include <bits/stdc++.h>
using namespace std;

int solve(int k, vector<int> s) {
    int ans=0;
    int sz=s.size();
    vector<int> v(k,0);
    for(int i=0; i<sz; ++i) {
       v[s[i]%k]++;
    }
    for(int i=1; i<=k/2; ++i){
        if (i != k-i)
            ans += max(v[i], v[k-i]);
        else {
            if (v[i])
                ans++;
        }
    }
    if (v[0])
        ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];

    int ans=solve(k,a);
    cout<<ans<<"\n";

    return 0;
}

