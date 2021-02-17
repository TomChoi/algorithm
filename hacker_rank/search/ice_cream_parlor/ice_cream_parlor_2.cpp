#include <bits/stdc++.h>
using namespace std;

#define N 2

vector<int> solve(int m, vector<int> arr) {
    vector<int> ans(N);
    int s=arr.size();
    map<int, int> mp;

    for(int i=0; i<s; i++) {
        int y = m - arr[i];
        auto it = mp.find(y);
        if (it != mp.end()) {
            ans[0] = it->second;
            ans[1] = i+1;
            return ans;
        }
        mp[arr[i]] = i+1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    vector<int> m(t), n(t);
    vector<vector<int>> arr(t);

    for(int i=0; i<t; ++i) {
        cin>>m[i]>>n[i];
        arr[i].resize(n[i]);
        for(int j=0; j<n[i];++j) {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<t; ++i) {
        vector<int> ans=solve(m[i], arr[i]);
        for(int e: ans)
            cout<<e<<" ";
        cout<<"\n";
    }
    
    return 0;
}
