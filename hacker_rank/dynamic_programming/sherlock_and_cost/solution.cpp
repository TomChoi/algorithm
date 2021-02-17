#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> B) {
    int ans = 0;
    int s=B.size();

    bool check = true;
    for(int i=0; i<s; ++i)
        if(B[i] > 1) check=false;
    if(check)
        return 0;

    for(int j=1; j<s; ++j)
        ans += abs(B[j] - B[j-1]); 

    for(int i=0; i<s; ++i) {
        vector<int> A=B;
        if(A[i] != 1){
            A[i] = 1;
            ans = max(ans, solve(A));
        }
    }
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

