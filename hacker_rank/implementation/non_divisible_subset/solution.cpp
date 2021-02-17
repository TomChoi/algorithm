#include <bits/stdc++.h>
using namespace std;

int solve(int k, vector<int> s) {
    int ans = 0;
    int sz=s.size();
    for(int i=0; i<sz-1; ++i) {
        for(int j=i+1; j<sz; ++j) {
            if (s[i] && s[j]) {
                if ((s[i] + s[j])%k == 0) {
                    vector<int> a1=s, a2=s;
                    a1[i]=0;
                    a2[j]=0;
                    return max(solve(k, a1), solve(k, a2));
                }
            }
        }
    }
    for(int i=0; i<sz; ++i)
        if (s[i]) ans++;
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

