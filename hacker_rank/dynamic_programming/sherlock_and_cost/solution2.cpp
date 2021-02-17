#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> B) {
    int ans = 0;
    int s=B.size();

    int sum1=0, sum2=0;
    for(int i=1; i<s; ++i) {
        int m1 = max(abs(B[i-1] - B[i])+sum1, abs(1-B[i])+sum2);
        int m2 = max(abs(B[i-1] - 1) + sum1, abs(1-1)+sum2);
        sum1 = m1;
        sum2 = m2;
    }
    ans = max(sum1, sum2);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    cin>>t>>n;

    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin>>a[i];
    }
    int ans=solve(a);
    cout<<ans<<"\n";

    return 0;
}

