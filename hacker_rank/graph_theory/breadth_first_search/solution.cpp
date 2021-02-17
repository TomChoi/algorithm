#include <bits/stdc++.h>
using namespace std;

const int mxN=1000;

vector<int> solve(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> ans(n-1);
    vector<int> dist(n+1);
    vector<bool> visited(n+1);
    queue<int> q;
    vector<unordered_set<int>> adj(mxN);
    for(auto e: edges) {
        adj[e[0]].insert(e[1]);
        adj[e[1]].insert(e[0]);
    }
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    while(!q.empty()) {
        int t=q.front();q.pop();
        for(auto e: adj[t]) {
            if(!visited[e]) {
                dist[e]=dist[t] + 1;
                visited[e]=true;
                q.push(e);
            }
        }
    } 

    int sz=dist.size();
    int cnt=0;
    for(int i=1; i<sz; ++i) {
        if (i!=s){
            if (dist[i]) {
                ans[cnt++] = dist[i]*6;
            } else {
                ans[cnt++] = -1;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    vector<int> n(q), m(q), s(q);
    vector<vector<vector<int>>> e(q);

    for(int i=0; i<q; ++i) {
        cin>>n[i]>>m[i];
        e[i].resize(m[i]);
        for(int j=0; j<m[i]; ++j) {
            e[i][j].resize(2);
            cin>>e[i][j][0]>>e[i][j][1];
        }
        cin>>s[i];
    }
    
    for(int i=0; i<q; ++i) {
        vector<int> ans=solve(n[i],m[i],e[i],s[i]);
        for(int e:ans)
            cout<<e<<", ";
        cout<<"\n"<<"\n";
    }

    return 0;
}
