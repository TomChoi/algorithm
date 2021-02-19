#include <bits/stdc++.h>
using namespace std;

long solve(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    long ans=0;

    if(c_lib<c_road) return (long)n*c_lib;

    vector<int> list(n);
    vector<int> size(n);

    for(int i=0; i<n; ++i) {
        list[i]=i;
        size[i]=1;
    }

    function<int(int)> find = [&list] (int a) {
        while(a!=list[a]) a=list[a];
        return a;
    };

    function<int(int,int)> same = [find] (int a, int b) {
        return find(a) == find(b);
    };

    function<int(int, int)> unite = [&list, &size, find] (int a, int b) {
        a=find(a);
        b=find(b);
        if(size[a]<size[b]) std::swap(a,b);
        list[b]=a;
        size[a]+=size[b];
        size[b]=0;
        return 0;
    };
    
    for(auto c: cities) {
        int a=c[0]-1, b=c[1]-1;
        if(same(a,b)) continue;
        unite(a,b);
    }

    for(int i=0; i<n; ++i)
        if(size[i])
            ans += (size[i]-1)*c_road + c_lib;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q, n, m, c_lib, c_road;
    cin>>q>>n>>m>>c_lib>>c_road;
    vector<vector<int>> cities(m);
    for(int i=0; i<m; ++i){
        cities[i].resize(2);
        cin>>cities[i][0]>>cities[i][1];
    }

    long ans=solve(n,c_lib,c_road, cities);
    cout<<ans<<"\n";

    return 0;
}
