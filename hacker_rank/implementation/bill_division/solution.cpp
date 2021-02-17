#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> bill, int k, int b) {
    int sum=0;
    int sz=bill.size();
    for(int i=0; i<sz; ++i){
        if(i != k) sum += bill[i];
    }
    int diff=b-(sum/2);
    if(diff) {
        cout<<diff<<"\n";
    } else {
        cout<<"Bon Appetit"<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,b;
    cin>>n>>k;
    vector<int> ar(n);
    for(int i=0; i<n; ++i)
        cin>>ar[i];

    cin>>b;

    solve(ar, k, b);
    return 0;
}
