#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

bool comp(vector<int> v1, vector<int> v2) {
    return v1[1]<v2[1];
}

int solve(int n, int m, int k, vector<vector<int>> track) {
    ull ans=(ull)n*m;
    cout<<n<<endl;
    cout<<m<<endl;
    unordered_map<int, int> mp; 
    cout<<"ans: "<<ans<<endl;
    sort(track.begin(), track.end(), comp);
    cout<<"?"<<endl;
    for(vector<int> t: track){
        int r=t[0];
        int s=mp[r], e=mp[r];
        if(mp[r] <= t[1]){
            s = t[1];
            e = t[2]+1;
        } else if(mp[r] <= t[2]){
            s = mp[r];
            e = t[2]+1;
        }
        ans -= e-s;
        cout<<"ans: "<<ans<<endl;
        mp[r] = e;

    }
    return (int)ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> t(k);
    for(int i=0; i<k; ++i) {
        t[i].resize(3);
        for(int j=0; j<3; ++j) {
            cin>>t[i][j];
        }
    }
    int ans=solve(n,m,k,t);
    cout<<ans<<"\n";

    return 0;
}
