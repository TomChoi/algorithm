#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <limits.h>

using namespace std;

vector<int> spliter(string s, char div) {
    vector<int> ans;
    istringstream ss(s);
    string buffer;
    while(getline(ss, buffer, div)) {
        if(buffer=="x")
            ans.push_back(0);
        else
            ans.push_back(stoi(buffer));
    }
    return ans;
}

int solve(int n, vector<vector<int>> edges) {
    int ans=0;

    vector<vector<pair<int,int>>> adj(n);
    vector<bool> v(n,false);
    vector<int> d(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(edges[i][j] || edges[j][i]) {
                int w=edges[i][j]!=0 ? edges[i][j]:edges[j][i];
                adj[i].push_back({j,w});
            }
        }
    }
    for(int i=0; i<n; ++i) {
        d[i]=INT_MAX;
    }
    d[0]=0; 
    q.push({0,0});

    while(!q.empty()) {
        pair<int,int> s=q.top(); q.pop();
        if(v[s.second]) continue;
        v[s.second]=true;
        for(pair<int,int> e: adj[s.second]) {
            int dist=d[s.second]+e.second;
            if(d[e.first]>dist) {
                d[e.first]=dist;
            }
            q.push({e.second, e.first});
        }
    }
    ans=*max_element(d.begin(), d.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> edges(n);
    for(int i=0; i<n; ++i) {
        edges[i].resize(n);
        string s;
        getline(cin, s);
        vector<int> res=spliter(s, ' ');
        int sz=res.size();
        for(int j=0; j<sz; ++j) {
            edges[i][j]=res[j];
        }
    }

    int ans=solve(n, edges);
    cout<<ans<<"\n";

    return 0;
}
    
