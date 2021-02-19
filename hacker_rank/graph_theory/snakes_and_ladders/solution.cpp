#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    const int N=100;
    vector<set<pair<int,int>>> adj(N+1);
    vector<bool> v(N+1);
    vector<int> d(N+1);
    queue<int> q;


    for(auto l: ladders){
        adj[l[0]].insert({l[1],0});
    }
    for(auto s: snakes){
        adj[s[0]].insert({s[1],0});
    }
    for(int i=1; i<N; ++i) {
        if(!adj[i].size()) {
            for(int j=1; j<=6; ++j)
                if(i+j>100)
                    adj[i].insert({100,1});
                else
                    adj[i].insert({i+j,1});
        }
    }
    for(int i=1; i<=N; ++i) {
        d[i]=INT_MAX;
    }

    d[1]=0;
    q.push(1);

    while(!q.empty()) {
        int s=q.front(); q.pop();
        if(v[s]) continue;
        v[s]=true;
        for(auto e: adj[s]) {
            int dist=d[s]+e.second;
            if(dist<d[e.first]) d[e.first]=dist;
            q.push(e.first);
        }
    }
    if(d[N]==INT_MAX)
        return -1;
    else
        return d[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n,m;
    cin>>t>>n;
    vector<vector<int>> ladders(n);
    for(int i=0; i<n; ++i){
        ladders[i].resize(2);
        cin>>ladders[i][0]>>ladders[i][1];
    }

    cin>>m;
    vector<vector<int>> snakes(m);
    for(int i=0; i<m; ++i){
        snakes[i].resize(2);
        cin>>snakes[i][0]>>snakes[i][1];
    }

    int ans=solve(ladders,snakes);
    cout<<ans<<"\n";

    return 0;
}

