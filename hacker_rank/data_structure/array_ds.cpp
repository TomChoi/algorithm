#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> a){
    int s=a.size();
    for(int i=0; i<s/2; ++i){
        int swap=a[i];
        a[i]=a[s-1-i];
        a[s-1-i]=swap;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin>>a[i];
    }
    vector<int> ans=solve(a);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}
