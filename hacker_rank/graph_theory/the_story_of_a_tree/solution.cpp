#include <bits/stdc++.h>
using namespace std;

typedef vector<unordered_set<int>> ed;
typedef vector<unordered_map<int,bool>> gu;

int gcd(int a, int b) {
    if(a==0)
        return b;
    return gcd(b%a, a);
}

void dfs(int s, ed& adj, vector<bool>& v, gu& gs) {
    for(auto e: adj[s]) {
       if(v[e]) continue;
       v[e]=true;
       if(gs[s].find(e) != gs[s].end()) {
           gs[s][e]=true;
       }
       dfs(e, adj, v, gs);
    }
}

string solve(int n, vector<vector<int>> edges, int k, vector<vector<int>> guesses) {
    int count=0;
    string ans="";
    ed adj(n+1);
    vector<bool> visited(n+1);
    gu gs(n+1);

    for(auto e: edges) {
        adj[e[0]].insert(e[1]);
        adj[e[1]].insert(e[0]);
    }

    for(auto g: guesses) {
        gs[g[0]][g[1]]=false;
    }
    
    for(int i=1; i<=n; ++i) {
        visited[i]=true;
        dfs(i, adj, visited, gs);

        int sz=visited.size();
        for(int j=1; j<sz; ++j) 
            visited[j]=false;
        bool check=true; 
        for(int j=1; j<=n; ++j) {
            for(auto it=gs[j].begin(); it !=gs[j].end(); ++it){
                if(!it->second) 
                    check=false;
                it->second=false;
            }
        }
        if (check) count++;
    }
    int d=gcd(count,n);
    ans=to_string(count/d) + "/" + to_string(n/d);
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q,n,g,k;
    cin>>q>>n;
    vector<vector<int>> edges(n-1);
    for(int i=0; i<n-1; ++i) {
        edges[i].resize(2);
        cin>>edges[i][0]>>edges[i][1];
    }

    cin>>g>>k;
    vector<vector<int>> guesses(g);
    for(int i=0; i<g; ++i){
        guesses[i].resize(2);
        cin>>guesses[i][0]>>guesses[i][1];
    }
    string ans=solve(n, edges, k, guesses);
    cout<<ans<<"\n";

    return 0;
}
