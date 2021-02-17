#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> x, int k) {
    int ans=0, i=0, s=0;

    sort(x.begin(), x.end());
    s=x.size();
    while(i<s) {
        ans++;
        int loc=x[i]+k;
        while(i<s && x[i]<=loc) ++i;
        loc=x[--i]+k;
        while(i<s && x[i]<=loc) ++i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> x(n);
    for(int i=0; i<n; ++i)
        cin>>x[i];

    int ans=solve(x, k);
    cout<<ans<<"\n";

    return 0;
}
