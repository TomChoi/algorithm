#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> s, int d, int m) {
    int ans=0;
    int sz=s.size();
    for(int i=0; i<sz; ++i) {
        int sum=0;
        for(int j=i; j<m+i; ++j) {
           sum += s[j];
        }
        if (sum == d) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,d,m;
    cin>>n;
    vector<int> ar(n);
    for(int i=0; i<n; ++i)
        cin>>ar[i];

    cin>>d>>m;

    int ans=solve(ar, d, m);
    cout<<ans<<"\n";

    return 0;
}
