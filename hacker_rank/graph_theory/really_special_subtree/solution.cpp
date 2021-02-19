#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[2]<b[2]) return true;
    else if(a[2]==b[2]) return a[0]+a[1]+a[2]<b[0]+b[1]+b[2];
    else return false;
}

int solve(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int ans=0, n=g_nodes;
    vector<int> list(n+1);
    vector<int> size(n+1,1);
    int sz=g_from.size();
    vector<vector<int>> edges(sz);
    for(int i=0; i<sz; ++i) {
        edges[i].resize(3);
        edges[i][0]=g_from[i];
        edges[i][1]=g_to[i];
        edges[i][2]=g_weight[i];
    }
    sort(edges.begin(), edges.end(), comp);

    for(int i=1; i<=n; ++i)
        list[i]=i;
    
    std::function<int(int)> find = [&list](int a)->int {
        while(list[a] != a) 
            a=list[a];
        return a;
    };

    auto same = [find](int a, int b)->bool {
        return find(a)==find(b);
    };

    for(auto e: edges) {
        int a=e[0], b=e[1], w=e[2];
        if(same(a,b)) continue;

        a=find(a);
        b=find(b);

        ans+=w;
        if(size[a]<size[b])
            swap(a,b);
        size[a]+=size[b];
        list[b]=a;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);

    vector<int> from(m);
    vector<int> to(m);
    vector<int> w(m);

    for(int i=0; i<m; ++i){
        edges[i].resize(3);
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }

    for(int i=0; i<m; ++i){
        from[i]=edges[i][0];
        to[i]=edges[i][1];
        w[i]=edges[i][2];
    }
    int ans=solve(n, from, to, w);
    cout<<ans<<"\n";

    return 0;
}
