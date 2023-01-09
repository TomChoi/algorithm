#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& adj, vector<bool>& taken) {
    int ans=0;
    int sz = taken.size(); 

    int firstman = -1;
    for (int i=0; i<sz; ++i) {
        if(!taken[i]) {
            firstman = i;
            break;
        }
    }

    if(firstman == -1)
        return 1;

    for(int i=firstman+1; i<sz; ++i) {
        if(!taken[i] && adj[firstman][i]) {
            taken[firstman] = true; taken[i] = true;
            ans += solve(adj, taken);
            taken[firstman] = false; taken[i] = false;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        vector<bool> taken(n);

        for(int i=0; i<n; ++i)
            adj[i].resize(n);

        for(int i=0; i<m; ++i) {
            int n1, n2;
            cin>>n1>>n2;
            adj[n1][n2] = 1;
            adj[n2][n1] = 1;
        }

        int ans = solve(adj, taken);
        cout<<ans<<endl;
    }

    return 0;
}
        
