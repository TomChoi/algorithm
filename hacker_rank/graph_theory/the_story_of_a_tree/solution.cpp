#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef map<int, vector<int>> mym;

int gcd(int a, int b) {
    if(a==0)
        return b;
    return gcd(b%a, a);
}

bool dfs(mym m, mym gm, vector<bool> v, int s) {
    for(auto e: m[s]){
        if(v[e]) continue;
        v[e]=true;
        auto it=gm.find(e);
        if(it != gm.end()) {
            for(int n: gm[e])
                if(v[n]) return false; 
        }
        if(!dfs(m,gm,v,e))
            return false;
    }
    return true;
}

string solve(int n, vector<vector<int>> edges, int k, vector<vector<int>> gesses) {
    string ans="";
    int cnt=0;
    
    mym m;
    mym gm;
    
    for(auto v: edges){
        m[v[0]].push_back(v[1]);
        m[v[1]].push_back(v[0]);
    }
    
    for(auto v: gesses){
        gm[v[0]].push_back(v[1]);
    }

    for(int i=1; i<=n; ++i) {
        vector<bool> v(n+1, false);
        v[i]=true;
        if(dfs(m, gm, v, i))
            cnt++;
    }

    int d=gcd(cnt,n);
    ans=to_string(cnt/d) + "/" + to_string(n/d);
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n;
        cin>>n;
        vector<vector<int>> e(n-1);
        for(int i=0; i<n-1; ++i){
            e[i].resize(2);
            for(int j=0; j<2; ++j)
                cin>>e[i][j];
        }
        int g,k;
        cin>>g>>k;
        vector<vector<int>> gesses(g);
        for(int i=0; i<g; ++i){
            gesses[i].resize(2);
            for(int j=0; j<2; ++j)
                cin>>gesses[i][j];
        }
        
        string ans=solve(n, e, k, gesses);
        cout<<ans<<"\n";
    }
    return 0;
}
