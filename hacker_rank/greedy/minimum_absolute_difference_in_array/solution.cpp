#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int ans=INT_MAX; 
    int s=arr.size(); 
    sort(arr.begin(), arr.end());
    for(int i=0; i<s-1; i++) {
        int m = abs(arr[i] - arr[i+1]);
        if(ans>m) ans=m;
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

