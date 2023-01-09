#include <iostream>

using namespace std;
typedef vector<vector<pair<char, char>>> AD;

void dfs(int s, string& str, AD& adj, vector<bool>& v) {
    if(v[s]) return;
    v[s]=true;
    str+=adj[s].second;
    for(auto e: adj[s]) {
        dfs(e.first, str, adj, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<char>> edges(m); 
    for(int i=0; i<edges; ++i) {
        edges[i].resize(3);
        for(int j=0; j<3; ++j) {
            cin>>edges[i][j];
        }
    }

    AD adj(n+1);
    for(auto e: edges) {
        adj[e[0]] = {e[1],e[2]};
        adj[e[1]] = {e[0],e[2]};
    }

    string str="";
    vector<bool> v;
    
    dfs(1, s, adj, v);
