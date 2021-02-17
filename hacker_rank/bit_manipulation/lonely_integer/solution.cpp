#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a) {
    const int Max=100;
    const int N=30;
    int ans=0;
    int sz=a.size();
    vector<int> n(ceil((float)Max/N));
    for(int i=0; i<sz; ++i) {
        int s=a[i]/N;
        n[s] ^= (1<<(a[i]%N));
    }
   
    for(int i=0; i<n.size(); ++i) {
        if (n[i]){ 
            ans = __builtin_ctz(n[i]) + (i*N);
        }
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
