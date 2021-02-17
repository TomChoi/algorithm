#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r) {
    int ans=0;

    for(int i=l; i<=r; ++i) {
        for(int j=i; j<=r; ++j) {
            int n=i^j;
            if(n>ans)
                ans=n;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l,r;
    cin>>l>>r;

    int ans=solve(l,r);
    cout<<ans<<"\n";

    return 0;
}
