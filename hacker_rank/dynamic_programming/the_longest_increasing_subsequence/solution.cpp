#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int ans=0;
    int s=arr.size();
    vector<int> dp(s);
    
    for(int i=0; i<s; ++i) {
        int c=0;
        for(int j=0; j<i; ++j) {
            if(arr[i] > arr[j]) {
                c=max(c, dp[j]);
            }
        }
        dp[i] = c+1;
        ans=max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; ++i)
        cin>>a[i];

    int ans=solve(a);
    cout<<ans<<"\n";

    return 0;
}
