#include <bits/stdc++.h>
using namespace std;

#define N 2
vector<int> solve(int m, vector<int> arr) {
    vector<int> ans(N);
    vector<int> c(arr.size());
    for(int i=0; i<arr.size(); ++i){
        if(i>=arr.size()-N)
            c[i]=1;
        else
            c[i]=0;
    }
    sort(c.begin(), c.end());
    do {
        int sum=0,cnt=0;
        for(int i=0; i<c.size(); ++i){
            if(c[i]){
                if (c[i]>=m)
                    continue;
                ans[cnt++]=i+1;
                sum+=arr[i];
            }
        }
        if(sum==m)
            return ans;

    } while(next_permutation(c.begin(), c.end()));
    cout<<"permutation error"<<"\n";
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    
    vector<int>m(t),n(t);
    vector<vector<int>> arr(t);
    
    for(int i=0; i<t; ++i){
        cin>>m[i]>>n[i];
        arr[i].resize(n[i]);
        for(int j=0; j<n[i]; ++j) 
            cin>>arr[i][j];
    }

    for(int i=0; i<t; ++i) {
        vector<int> ans = solve(m[i], arr[i]);
        for(int e: ans)
            cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}
