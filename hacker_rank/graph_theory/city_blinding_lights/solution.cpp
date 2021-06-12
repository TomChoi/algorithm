#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <map>

using namespace std;

vector<int> solve(int n, vector<vector<int>> edges, vector<vector<int>> quries) {
    vector<int> ans;
    int qn=quries.size(), en=edges.size();
    vector<vector<int>> dist(n+1);
    for(int i=1; i<=n; ++i) {
        dist[i].resize(n+1);
        for(int j=1; j<=n; ++j) {
            if(i==j) {
                dist[i][j]=0;
            } else {
                dist[i][j]=INT_MAX;
            }
        }
    }

    vector<map<int,int>> adj(n+1);
    for(vector<int> e: edges) {
        adj[e[0]][e[1]]=e[2];
    }

    for(vector<int> qur: quries) {
        if(qur[0]==qur[1] || dist[qur[0]][qur[1]] != INT_MAX) {
            ans.push_back(dist[qur[0]][qur[1]]);
            continue;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> v(n+1, false);
        q.push({0,qur[0]});

        while(!q.empty()) {
            pair<int,int> s=q.top(); q.pop();
            if(v[s.second]) continue;
            v[s.second]=true;
            for(pair<int,int> e: adj[s.second]) {
                int d=dist[qur[0]][s.second]+e.second;
                if(dist[qur[0]][e.first]>d)
                    dist[qur[0]][e.first]=d;
                q.push({e.second, e.first});
            }
        }
        int d=dist[qur[0]][qur[1]];
        if(d==INT_MAX)
            d=-1;
        ans.push_back(d);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> edges(m);
    for(int i=0; i<m; ++i) {
        edges[i].resize(3);
        for(int j=0; j<3; ++j) {
            cin>>edges[i][j];
        }
    }
    int q;
    cin>>q;
    vector<vector<int>> quries(q);
    for(int i=0; i<q; ++i) {
        quries[i].resize(2);
        for(int j=0; j<2; ++j) {
            cin>>quries[i][j];
        }
    }

    vector<int> ans=solve(n, edges, quries);
    for(int e: ans) {
        cout<<e<<"\n";
    }

    return 0;
}
