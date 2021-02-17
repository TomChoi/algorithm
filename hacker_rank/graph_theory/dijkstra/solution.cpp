#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<vector<int>> edges, int s) {
    vector<int> ans(n-1);
    vector<int> dist(n+1);
    vector<int> visited(n+1);
    vector<set<pair<int, int>>> adj(n+1);
    priority_queue<pair<int,int>> q;

    int sz=edges.size();
    for(auto e: edges) {
       adj[e[0]].insert({e[1],e[2]});
       adj[e[1]].insert({e[0],e[2]});
    }

    for(int i=0; i<n+1; ++i) {
        dist[i]=INT_MAX;
    }

    dist[s]=0;
    q.push({0,s});

    while(!q.empty()) {
        int t=q.top().second; q.pop();
        if(visited[t]) continue;
        visited[t]=true;
        for(auto e: adj[t]) {
            int d=dist[t] + e.second;
            if(d<dist[e.first])
                dist[e.first]=d;
            q.push({-dist[e.first],e.first});
        }
    }
    int cnt=0;
    for(int i=1; i<=n; ++i){
        if(i!=s) {
            if(dist[i] == INT_MAX)
                ans[cnt++]=-1;
            else 
                ans[cnt++]=dist[i];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n,m,s;
    cin>>t>>n>>m;

    vector<vector<int>> e(m);
    for(int i=0; i<m; ++i){
        e[i].resize(3);
        for(int j=0; j<3; ++j)
            cin>>e[i][j];
    }
    cin>>s;
    vector<int> ans = solve(n, e, s);
    for(int e: ans)
        cout<<e<<" ";
    cout<<"\n";

    return 0;
}

    
