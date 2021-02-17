#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<vector<int>> queries) {
    // create 'n' empty arrays
    vector<int> ans;
    vector<vector<int>> a(n);
    int la=0;
    for(vector<int> q: queries){
        if(q[0]==1){
            a[(q[1]^la)%n].push_back(q[2]);
        }else {
            int idx=(q[1]^la)%n;
            la=a[idx][q[2]%a[idx].size()];
            ans.push_back(la);
        }
    }
    return ans; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, qn;
    cin>>n>>qn;
    vector<vector<int>> q(qn);
    for(int i=0; i<qn; ++i){
        q[i].resize(3);
        for(int j=0; j<3; ++j){
           cin>>q[i][j];
        }
    }

    vector<int> ans=solve(n, q);
    for(int e: ans)
        cout<<e<<"\n";

    return 0;
}
