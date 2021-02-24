#include <bits/stdc++.h>
using namespace std;

// least common multiple
int lcm(vector<int> a) {

}

// largest common factor
int lcf(vector<int> a) {

}

int 
int solve(vector<int> a, vector<int> b) {
    int ans=0;

    int lcm=lcm(a);
    int lcf=lcf(b);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    vector<int> b(m);

    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<m; ++i)
        cin>>b[i];

    int ans=solve(a,b);
    cout<<ans<<"\n";

    return 0;
}
