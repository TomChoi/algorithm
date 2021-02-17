#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int ans=0;
    int sz=arr.size();
    map<int,int> m;
    for(int i=0; i<sz; ++i) {
        m[arr[i]]++;
    }
    int max=0;
    for(auto e: m){
       if(e.second > max){
           max=e.second; 
           ans=e.first;
       }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i)
        cin>>arr[i];

    int ans=solve(arr);
    cout<<ans<<"\n";

    return 0;
}
