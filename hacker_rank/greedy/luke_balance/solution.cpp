#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> v1, vector<int> v2) {
    return v1[0]>v2[0];
}

int solve(int k, vector<vector<int>> contests) {
    int ans=0;
    int s=contests.size();
    sort(contests.begin(), contests.end(), comp);
    for(vector<int> c: contests) {
        if(c[1]) {
            if (k) {
                k--;
                ans += c[0];
            } else {
                ans -= c[0];
            }
        }else{
            ans += c[0];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<2; ++j)
            cin>>a[i][0]>>a[i][1];

    int ans=solve(k, a);
    cout<<ans<<"\n";

    return 0;
}

