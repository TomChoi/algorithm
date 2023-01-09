#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int N=6;
vector<int> adj[N];
vector<int> visited(N);
queue<int> q;
vector<int> dist(N);

void dfs(int s) {
    if(visited[s]) return;
    visited[s]=true;
    cout<<s<<", ";
    for(auto u: adj[s]) {
        dfs(u);
    }
}

void bfs(int x) {
    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    cout<<x<<", ";
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(int n: adj[s]) {
            if(visited[n]) continue;
            cout<<n<<", ";
            visited[n]=true;
            dist[n] = dist[s] + 1;
            q.push(n);
        }
    }
}

int main() {
    vector<int> a={1,2};
    vector<int> b={3,4};
    
    for(int i=0; i<2; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    for(int e: b)
        cout<<e<<" ";
    cout<<endl;
    
    std::swap(a,b);
    cout<<endl;
    for(int i=0; i<2; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    for(int e: b)
        cout<<e<<" ";
    cout<<endl;
    
    return 0;
}
