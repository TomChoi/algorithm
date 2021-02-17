#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> x, int k) {
    int ans = 0;
    int s=x.size();
    int r=k,p=x[0],d=0;
    sort(x.begin(), x.end());
    for(int i=0; i<s;) {
        if (i==s-1){
            ans++;
            return ans;
        }
        d+=x[i+1] - x[i];
        if (d>k) {
            ans++;
            int n=0;
            while(i<s-1) {
                n += x[i+1] - x[i];
                if (n<=k)
                    i++;
                else
                    break;
            }
            d=0;
        }
        i++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin>>a[i];
    }

    int ans=solve(a, k);
    cout<<ans<<"\n";

    return 0;
}
