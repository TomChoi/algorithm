#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<pair<int,int>>> gp;
int solve(gp adj, map<pair<int, int>, bool> visited, vector<int> dist, int st, int ed) {
    int szd=dist.size(); 
    for(int i=0; i<szd; ++i) {
        dist[i] = INT_MAX;
    }
    queue<int> q;
    dist[st]=0;
    q.push(st);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        for(auto e: adj[s]) {
            if(visited[make_pair(s,e.first)]) continue;
            visited[make_pair(s,e.first)]=true;
            int d = e.second + dist[s];
            if (d < dist[e.first])
                dist[e.first] = d;
            q.push(e.first);
        }
    }
    return dist[ed];
}

void make_adj(gp& adj) {
    adj[1] = {{2,5},{3,3},{4,7}}; 
    adj[2] = {{1,5},{4,3},{5,2}};
    adj[3] = {{1,3},{4,1}};
    adj[4] = {{2,3},{3,1},{5,2}};
    adj[5] = {{2,2},{4,2}};
}


int main() {
    const int N=5+1;
    gp adj(N);
    map<pair<int,int>,bool> visited;
    vector<int> dist(N);

    make_adj(adj);
    int s,e;
    cin>>s>>e;

    int ans=solve(adj, visited, dist, s, e);
    cout<<ans<<endl;
    
    return 0;
}
