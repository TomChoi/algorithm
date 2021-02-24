#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve(int n, vector<int> ar) {
    int ans=0;
    map<int,int> m;
    for(int e: ar)
        m[e]++;
    for(auto it=m.begin(); it!=m.end(); ++it)
        ans += it->second/2;
    return ans; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int ans=solve(n,a);
    cout<<ans<<"\n";

    return 0;
}
