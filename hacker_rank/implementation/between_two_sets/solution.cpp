#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, vector<int> b) {
    int ans=0;
    int sza=a.size(), szb=b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mxN=1;
    int miN=b[0];

    for(int i=0; i<sza-1; ++i) {
        for(int j=i+1; j<sza; ++j) {
            if (a[j]%a[i] == 0)
                a[i] = 0;
        }
    }
    for(int i=0; i<sza; ++i)
        if(a[i])
            mxN *= a[i];
    
    int max = mxN;
    while(mxN <= miN) {
        bool check=true;
        for(int i=0; i<szb; ++i) {
           if(b[i]%mxN) {
               check=false;
               break;
           }
        }
        if (check) {
            ans++;
        }
        mxN += max; 
    }
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
