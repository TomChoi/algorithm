#include <bits/stdc++.h>
using namespace std;

int solve(int V, vector<int> arr) {
    int s=arr.size();
    for(int i=0; i<s; ++i){
        if(arr[i]==V)
            return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v,n;
    vector<int> ar(n);
    cin>>v>>n;
    for(int i=0; i<n; ++i){
        cin>>ar[i];
    }
    int ans=solve(v, ar);
    cout<<ans<<"\n";

    return 0;
}
