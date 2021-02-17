#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    vector<int> ans(2, 0);
    for(int e: apples){
        if (s <= a+e && t >= a+e)
            ans[0]++;
    }
    for(int e: oranges){
        if (s <= b+e && t >= b+e)
            ans[1]++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s,t,a,b,m,n;
    cin>>s>>t;
    cin>>a>>b;
    cin>>m>>n;
    vector<int> ad(m);
    vector<int> bd(n);
    for(int i=0; i<m; ++i)
        cin>>ad[i];
    for(int i=0; i<n; ++i)
        cin>>bd[i];

    vector<int> ans=solve(s, t, a, b, ad, bd);
    for(int e: ans)
        cout<<e<<"\n";

    return 0;
} 
