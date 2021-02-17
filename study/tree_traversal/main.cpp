#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=8;
vector<vector<int>> adj(N+1);

void dfs(int s, int e) {
    // process node s
    for(auto u: adj[s]) {
        if(u != e){
            cout<<u<<", ";
            dfs(u,s);
        } 
    }
}

int main() {

    adj[1] = {2,3,4};
    adj[2] = {1,5,6};
    adj[3] = {1};
    adj[4] = {1,7};
    adj[5] = {2};
    adj[6] = {2,8};
    adj[7] = {4};
    adj[8] = {6};
    
    int s;
    cin>>s;
    dfs(s,0);

    return 0;
}

