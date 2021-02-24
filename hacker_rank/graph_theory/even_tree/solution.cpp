#include <iostream>
#include <vector>
#include <map>

using namespace std;

int find_even(map<int, vector<int>> m, vector<bool> v, int n, int& ans) {
    int sum=1;
    for(auto e: m[n]) {
        if(v[e]) continue;
        v[e]=true;
        sum += find_even(m, v, e, ans);
    }
    if (sum%2==0 && n != 1)
        ans++;
    return sum;
}
// find maximum number of edges
int solve(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    int ans=0; 
    map<int, vector<int>> m;
    vector<bool> v(t_nodes+1, false);
    for(int i=0; i<t_edges; ++i) {
        m[t_from[i]].push_back(t_to[i]);
        m[t_to[i]].push_back(t_from[i]);
    }
    v[1]=true;
    find_even(m, v, 1, ans);   
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,e;
    cin>>n>>e;
    vector<int> from(e);
    vector<int> to(e);
    for(int i=0; i<e; ++i)
        cin>>from[i]>>to[i];

    int ans=solve(n, e, from, to);
    cout<<ans<<"\n";
    return 0;
}
