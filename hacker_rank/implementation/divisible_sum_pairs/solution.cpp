#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> ar) {
    int ans=0;

    for(int i=0; i<n-1; ++i) {
        for(int j=i+1; j<n; ++j) {
            if((ar[i] + ar[j])%k==0) ans++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> ar(n);
    for(int i=0; i<n; ++i)
        cin>>ar[i];

    int ans = solve(n, k, ar);
    cout<<ans<<"\n";

    return 0;
}
