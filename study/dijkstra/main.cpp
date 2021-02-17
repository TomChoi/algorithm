#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    const int N=5+1;
    vector<int> dist(N);
    vector<vector<pair<int, int>>> adj(N);
    priority_queue<pair<int, int>> q;
    vector<bool> processed(N);

    // make adjacency list
    adj[1] = {{2,5},{4,9},{5,1}};
    adj[2] = {{3,2},{1,5}};
    adj[3] = {{2,2},{4,6}};
    adj[4] = {{3,6},{1,9},{5,2}};
    adj[5] = {{4,2},{1,1}};
    
    // get input argument start, end
    int st,ed;
    cin>>st>>ed;

    // dijkstra's algorithm
    // initialize all distance to INF
    for(int i=0; i<N; ++i)
        dist[i]=INT_MAX;

    dist[st] = 0;
    // q contains pairs of the form
    // (-d, x)
    // the current distance to node x is d.
    q.push({0, st});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
            processed[a]=true;

        for(auto u: adj[a]) {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }

    cout<<dist[ed]<<endl;

    return 0;
}
