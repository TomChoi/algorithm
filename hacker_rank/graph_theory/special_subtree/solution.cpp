#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> edges, int start) {
    int ans=0;
    vector<set<pair<int, int>>> adj(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<bool> v(n+1);

    for(auto e: edges) {
        adj[e[0]].insert({e[1], e[2]});
        adj[e[1]].insert({e[0], e[2]});
    }
    
    q.push({0,start});

    while(!q.empty()) {
        int w=q.top().first;
        int s=q.top().second;
        q.pop();
        if (v[s]) continue;
        v[s]=true;
        ans += w;
        for(auto e: adj[s]){
            q.push({e.second, e.first});
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,s;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0; i<m; ++i) {
        edges[i].resize(3);
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    cin>>s;
    int ans=solve(n, edges, s);
    cout<<ans<<"\n";

    return 0;
}
